<?php
/**
 * @file
 * Views-related functions.
 */

/**
 * Implements hook_preprocess_views_view().
 */
function sugufi_preprocess_views_view(&$vars) {
  // Modify classes to follow SMACSS naming convention.
  $tmp_classes_array = $vars['classes_array'];
  $vars['classes_array'] = preg_replace('/^view-(?!-)/', 'view--', $vars['classes_array']);

  // We add back the default Views classes, regardless of SMACSS theme setting,
  // to make sure ajaxified views still work.
  $vars['classes_array'] = array_unique (array_merge($vars['classes_array'], $tmp_classes_array));
}

/**
 * Implements hook_preprocess_views_view_grid().
 */
function sugufi_preprocess_views_view_grid(&$vars) {
  // Modify classes to follow SMACSS naming convention.
  $vars['class'] = preg_replace(
    array('/views-view-grid/', '/cols-/'),
    array('layout-grid', 'layout-grid--cols-'),
    $vars['class']
  );
  $vars['class'] .= ' layout-grid--' . drupal_html_class($vars['view']->name);
  $vars['row_classes'] = preg_replace('/row-/', 'layout-grid__row--', $vars['row_classes']);
  foreach ($vars['column_classes'] as $key => $value) {
    $vars['column_classes'][$key] = preg_replace('/col-/', 'layout-grid__column--', $vars['column_classes'][$key]);
  }
}

/**
 * Implements hook_preprocess_views_exposed_form().
 */
function sugufi_preprocess_views_exposed_form(&$vars) {
    if($vars['form']['#id']=='views-exposed-form-business-page'){
        $vars['form']['field_business_category']['#options']['All'] = t('Choose Business Category');
    }
}
