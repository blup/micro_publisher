<?php
// $Id: micro-publisher.tpl.php, v 1.0 2010/12/01 04:20:00 blup Exp $

/**
 * @file
 * Default theme implementation for micros.
 *
 * Available variables:
 * - $author: micro author. Can be link or plain text.
 * - $content: An array of micro items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $created: Formatted date and time for when the micro was created.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $micro->created variable.
 * - $changed: Formatted date and time for when the micro was last changed.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $micro->changed variable.
 * - $new: New micro marker.
 * - $permalink: micro permalink.
 * - $picture: Authors picture.
 * - $signature: Authors signature.
 * - $status: micro status. Possible values are:
 *   micro-unpublished, micro-published or micro-preview.
 * - $title: Linked title.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - micro: The current template type, i.e., "theming hook".
 *   - micro-by-anonymous: micro by an unregistered user.
 *   - micro-by-node-author: micro by the author of the parent node.
 *   - micro-preview: When previewing a new or edited micro.
 *   The following applies only to viewers who are registered users:
 *   - micro-unpublished: An unpublished micro visible only to administrators.
 *   - micro-by-viewer: micro by the user currently viewing the page.
 *   - micro-new: New micro since last the visit.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * These two variables are provided for context:
 * - $micro: Full micro object.
 * - $node: Node object the micros are attached to.
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_micro()
 * @see template_process()
 * @see theme_micro()
 */
?>
<div class="micro-publisher tabs-bottom">
  <ul>
    <?php if(isset($status_name)): ?><li><a href="#status"><?php print $status_name; ?></a></li><?php endif; ?>
    <?php if(isset($image_name)): ?><li><a href="#image"><?php print $image_name; ?></a></li><?php endif; ?>
    <?php if(isset($video_name)): ?><li><a href="#video"><?php print $video_name; ?></a></li><?php endif; ?>
    <?php if(isset($file_name)): ?><li><a href="#file"><?php print $file_name; ?></a></li><?php endif; ?>
    <?php if(isset($event_name)): ?><li><a href="#event"><?php print $event_name; ?></a></li><?php endif; ?>
  </ul>
  <?php if(isset($status_name)): ?>
    <div id="status">
      <?php print render($status_form); ?>
    </div>
  <?php endif; ?>
  <?php if(isset($image_name)): ?>
    <div id="image">
      <?php print render($image_form); ?>
    </div>
  <?php endif; ?>
  <?php if(isset($video_name)): ?>
    <div id="video">
      <?php print render($video_form); ?>
    </div>
  <?php endif; ?>
  <?php if(isset($file_name)): ?>
    <div id="file">
      <?php print render($file_form); ?>
    </div>
  <?php endif; ?>
  <?php if(isset($event_name)): ?>
    <div id="event">
      <?php print render($event_form); ?>
    </div>
  <?php endif; ?>
</div>
