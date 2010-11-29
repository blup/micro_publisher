<?php
// $Id: micro_publisher.admin.inc,v 0.1 2011/01/01 04:20:00 blup Exp $

/**
 * @file
 * Administrative page callbacks for the micro publisher modules.
 */

function micro_publisher_settings_form($form, &$form_state, $entity) {
  $entities = micro_get_entities();
  $micro_types = micro_type_get_types();
  $publisher_types = array('status', 'event', 'image', 'video', 'file');
  $form['#entity_type'] = $entity;

  foreach ($publisher_types as $type) {
    $form[$type] = array(
      '#type' => 'fieldset',
      '#title' => t('@type', array('@type' => ucfirst($type))),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form[$type][$type . '_bundles'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Bundles'),
      '#options' => $entities[$entity]['bundles'],
      '#default_value' => $micro_types['micro_publisher_' . $entity . '_' . $type]->bundles,
    );
  }

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save micro type'),
    '#weight' => 40,
  );

  return $form;
}

/**
 * Submit function for micro_publisher_settings_form().
 */
function micro_publisher_settings_form_submit($form, &$form_state) {
  $types = array('status', 'event', 'image', 'video', 'file');
  $micro_types = micro_type_get_types();
  foreach ($types as $type) {
    $publisher_type = 'micro_publisher_' . $form['#entity_type'] . '_' . $type;
    $publisher_type = $micro_types[$publisher_type];
    $publisher_type->bundles = $form_state['values'][$type . '_bundles'];

    $status = micro_type_save($publisher_type);
    if ($status == SAVED_UPDATED) {
      drupal_set_message(t('The micro type %name has been updated.', $t_args));
    }
  }

  micro_types_rebuild();
  $form_state['redirect'] = 'admin/structure/micro';
  return;
}
