<?php
// $Id: path.admin.inc,v 1.45 2010/09/11 03:04:43 dries Exp $

/**
 * @file
 * Administrative page callbacks for the Micro Publisher Node module.
 */

/**
 */
function micro_publisher_node_admin_overview($keys = NULL) {
  return drupal_get_form('micro_publisher_node_settings_form', $keys);
  /*$rows = array();
  $header[]='';
  $rows[]= 'ici';
  $build['path_table'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No URL aliases available. <a href="@link">Add URL alias</a>.', array('@link' => url('admin/config/search/path/add'))),
  );
  return $build;
  */
}

function micro_publisher_node_settings_form($form, &$form_state, $no_js_use = FALSE) {
  $infos = entity_get_info('node');

  $form['#attached']['css'] = array(
    drupal_get_path('module', 'micro_publisher_node') . '/publisher.css',
  );

  $form['apply'] = array(
    '#type' => 'fieldset',
    '#title' => t('Micro Node Publishers Setings'),
    '#description' => t('Choose your publishers for the node micro'),
  );

  /*
  * Todos
  */
  $form['apply']['todos'] = array(
    '#type' => 'fieldset',
    '#title' => t('Todos'),
  );
  $form['apply']['todos']['micro_publisher_node_todos'] = array(
    '#type' => 'checkbox',
    '#title' => t("Todo's handling"),
    '#default_value' => variable_get('micro_publisher_node_todos', TRUE),
    //'#description' => t("Whether to apply todo's"),
    '#ajax' => array(
         'wrapper' => 'todos-fieldset-wrapper',
         'callback' => 'micro_publisher_node_settings_form_todos_callback',
    ),
  );

  $form['apply']['todos']['todos-sub'] = array(
    '#type' => 'fieldset',
    '#title' => t('Todos node types'),
    '#description' => t('Choose which node types are eligible:'),
    // These provide the wrapper referred to in #ajax['wrapper'] above.
    '#prefix' => '<div id="todos-fieldset-wrapper">',
    '#suffix' => '</div>',
  );

  if (!empty($form_state['values']['micro_publisher_node_todos']) && $form_state['values']['micro_publisher_node_todos']) {
    foreach ($infos['bundles'] as $bundle) {
      //http://drupal.org/project/examples
      $form['apply']['todos']['todos-sub']['micro_publisher_node_todos'.$bundle['label']] = array(
        '#type' => 'checkbox',
        '#title' => t($bundle['label']),
        '#default_value' => variable_get('micro_publisher_node_todos', TRUE),
      );
    }
    $form['apply']['todos']['todos-sub']['#attributes'] = array('class' => array('show'));
  } else {
    //$form['apply']['todos']['todos-sub']['#title_display'] = 'invisible';
    $form['apply']['todos']['todos-sub']['#attributes'] = array('class' => array('hide'));
  }

  /*
  * Events
  */
  $form['apply']['events'] = array(
    '#type' => 'fieldset',
    '#title' => t('Events'),
  );
  $form['apply']['events']['micro_publisher_node_events'] = array(
    '#type' => 'checkbox',
    '#title' => t('Events handling'),
    '#default_value' => variable_get('micro_publisher_node_events', TRUE),
    //'#description' => t('Whether to apply milestones'),
    '#ajax' => array(
         'wrapper' => 'events-fieldset-wrapper',
         'callback' => 'micro_publisher_node_settings_form_events_callback',
    ),
  );

  $form['apply']['events']['events-sub'] = array(
    '#type' => 'fieldset',
    '#title' => t('Events node types'),
    '#description' => t('Choose which node types are eligible:'),
    // These provide the wrapper referred to in #ajax['wrapper'] above.
    '#prefix' => '<div id="events-fieldset-wrapper">',
    '#suffix' => '</div>',
  );
  if (!empty($form_state['values']['micro_publisher_node_events']) && $form_state['values']['micro_publisher_node_events']) {
    foreach ($infos['bundles'] as $bundle) {
      //http://drupal.org/project/examples
      $form['apply']['events']['events-sub']['micro_publisher_node_events'.$bundle['label']] = array(
        '#type' => 'checkbox',
        '#title' => t($bundle['label']),
        '#default_value' => variable_get('micro_publisher_node_events', TRUE),
      );
    }
    $form['apply']['events']['events-sub']['#attributes'] = array('class' => array('show'));
  } else {
    $form['apply']['events']['events-sub']['#attributes'] = array('class' => array('hide'));
  }

  /*
  * Images
  */
  $form['apply']['images'] = array(
    '#type' => 'fieldset',
    '#title' => t('Images'),
  );
  $form['apply']['images']['micro_publisher_node_images'] = array(
    '#type' => 'checkbox',
    '#title' => t('Images handling'),
    '#default_value' => variable_get('micro_publisher_node_images', TRUE),
    //'#description' => t('Whether to apply file upload'),
    '#ajax' => array(
         'wrapper' => 'images-fieldset-wrapper',
         'callback' => 'micro_publisher_node_settings_form_images_callback',
    ),

  );

  $form['apply']['images']['images-sub'] = array(
    '#type' => 'fieldset',
    '#title' => t('Images node types'),
    '#description' => t('Choose which node types are eligible:'),
    // These provide the wrapper referred to in #ajax['wrapper'] above.
    '#prefix' => '<div id="images-fieldset-wrapper">',
    '#suffix' => '</div>',
  );
  if (!empty($form_state['values']['micro_publisher_node_images']) && $form_state['values']['micro_publisher_node_images']) {

    foreach ($infos['bundles'] as $bundle) {
      //http://drupal.org/project/examples
      $form['apply']['images']['images-sub']['micro_publisher_node_images'.$bundle['label']] = array(
        '#type' => 'checkbox',
        '#title' => t($bundle['label']),
        '#default_value' => variable_get('micro_publisher_node_images', TRUE),
      );
    }
    $form['apply']['images']['images-sub']['#attributes'] = array('class' => array('show'));
  } else {
    $form['apply']['images']['images-sub']['#attributes'] = array('class' => array('hide'));
  }

  /*
  * Videos
  */
  $form['apply']['videos'] = array(
    '#type' => 'fieldset',
    '#title' => t('Videos'),
  );
  $form['apply']['videos']['micro_publisher_node_videos'] = array(
    '#type' => 'checkbox',
    '#title' => t('Videos handling'),
    '#default_value' => variable_get('micro_publisher_node_videos', TRUE),
    //'#description' => t('Whether to apply file upload'),
    '#ajax' => array(
         'wrapper' => 'videos-fieldset-wrapper',
         'callback' => 'micro_publisher_node_settings_form_videos_callback',
    ),

  );

  $form['apply']['videos']['videos-sub'] = array(
    '#type' => 'fieldset',
    '#title' => t('Videos node types'),
    '#description' => t('Choose which node types are eligible:'),
    // These provide the wrapper referred to in #ajax['wrapper'] above.
    '#prefix' => '<div id="videos-fieldset-wrapper">',
    '#suffix' => '</div>',
  );
  if (!empty($form_state['values']['micro_publisher_node_videos']) && $form_state['values']['micro_publisher_node_videos']) {

    foreach ($infos['bundles'] as $bundle) {
      //http://drupal.org/project/examples
      $form['apply']['videos']['videos-sub']['micro_publisher_node_videos'.$bundle['label']] = array(
        '#type' => 'checkbox',
        '#title' => t($bundle['label']),
        '#default_value' => variable_get('micro_publisher_node_videos', TRUE),
      );
    }
    $form['apply']['videos']['videos-sub']['#attributes'] = array('class' => array('show'));
  } else {
    $form['apply']['videos']['videos-sub']['#attributes'] = array('class' => array('hide'));
  }

  /*
  * Files
  */
  $form['apply']['files'] = array(
    '#type' => 'fieldset',
    '#title' => t('Files'),
  );
  $form['apply']['files']['micro_publisher_node_files'] = array(
    '#type' => 'checkbox',
    '#title' => t('Files handling'),
    '#default_value' => variable_get('micro_publisher_node_files', TRUE),
    //'#description' => t('Whether to apply file upload'),
    '#ajax' => array(
         'wrapper' => 'files-fieldset-wrapper',
         'callback' => 'micro_publisher_node_settings_form_files_callback',
    ),

  );

  $form['apply']['files']['files-sub'] = array(
    '#type' => 'fieldset',
    '#title' => t('Files node types'),
    '#description' => t('Choose which node types are eligible:'),
    // These provide the wrapper referred to in #ajax['wrapper'] above.
    '#prefix' => '<div id="files-fieldset-wrapper">',
    '#suffix' => '</div>',
  );
  if (!empty($form_state['values']['micro_publisher_node_files']) && $form_state['values']['micro_publisher_node_files']) {

    foreach ($infos['bundles'] as $bundle) {
      //http://drupal.org/project/examples
      $form['apply']['files']['files-sub']['micro_publisher_node_files'.$bundle['label']] = array(
        '#type' => 'checkbox',
        '#title' => t($bundle['label']),
        '#default_value' => variable_get('micro_publisher_node_files', TRUE),
      );
    }
    $form['apply']['files']['files-sub']['#attributes'] = array('class' => array('show'));
  } else {
    //$form['apply']['todos']['todos-sub']['#title_display'] = 'invisible';
    $form['apply']['files']['files-sub']['#attributes'] = array('class' => array('hide'));
  }


  $form['#submit'][] = 'search_admin_settings_submit';


  // This simply allows us to demonstrate no-javascript use without
  // actually turning off javascript in the browser. Removing the #ajax
  // element turns off AJAX behaviors on that element and as a result
  // ajax.js doesn't get loaded.

  if ($no_js_use) {
    // Remove the #ajax from the above, so ajax.js won't be loaded.
    unset($form['apply']['todos']['micro_publisher_node_todos']);
    unset($form['apply']['events']['micro_publisher_node_events']);
    unset($form['apply']['images']['micro_publisher_node_images']);
    unset($form['apply']['videos']['micro_publisher_node_videos']);
    unset($form['apply']['files']['micro_publisher_node_files']);
  }


  return system_settings_form($form);
}

/**
 * Callback that selects and returns the todos_fieldset.
 */
function micro_publisher_node_settings_form_todos_callback($form, $form_state) {
  return $form['apply']['todos']['todos-sub'];
}

/**
 * Callback that selects and returns the events_fieldset.
 */
function micro_publisher_node_settings_form_events_callback($form, $form_state) {
  return $form['apply']['events']['events-sub'];
}

/**
 * Callback that selects and returns the iamges_fieldset.
 */
function micro_publisher_node_settings_form_images_callback($form, $form_state) {
  return $form['apply']['images']['images-sub'];
}

/**
 * Callback that selects and returns the videos_fieldset.
 */
function micro_publisher_node_settings_form_videos_callback($form, $form_state) {
  return $form['apply']['videos']['videos-sub'];
}

/**
 * Callback that selects and returns the files_fieldset.
 */
function micro_publisher_node_settings_form_files_callback($form, $form_state) {
  return $form['apply']['files']['files-sub'];
}


/**
 * Validation function for micro_publisher_node_settings_form().
 *
 *//*
function micro_publisher_node_settings_form_validate($form, &$form_state) {
  $answer = $form_state['values']['question'];
  if ($answer !== t('George Washington')) {
    form_set_error('question', t('Wrong answer. Try again. (Hint: The right answer is "George Washington".)'));
  }
}*/

/**
 * Submit function for micro_publisher_node_settings_form().
 *//*
function micro_publisher_node_settings_form_submit($form, &$form_state) {
  // This is only executed when a button is pressed, not when the AJAXified
  // select is changed.
  // Now handle the case of the next, previous, and submit buttons.
  // only submit will result in actual submission, all others rebuild.
  switch($form_state['triggering_element']['#value']) {
    case t('Submit your answer'): // Submit: We're done.
      $form_state['rebuild'] = FALSE;
      $answer = $form_state['values']['question'];

      // Special handling for the checkbox.
      if ($answer == 1 && $form['questions_fieldset']['question']['#type'] == 'checkbox') {
        $answer = $form['questions_fieldset']['question']['#title'];
      }
      if ($answer === t('George Washington')) {
        drupal_set_message(t('You got the right answer: @answer', array('@answer' => $answer)));
      }
      else {
        drupal_set_message(t('Sorry, your answer (@answer) is wrong', array('@answer' => $answer)));
      }
      $form_state['rebuild'] = FALSE;
      return;
  }

  // Any other form element will cause rebuild of the form and present
  // it again.
  $form_state['rebuild'] = TRUE;
}*/

