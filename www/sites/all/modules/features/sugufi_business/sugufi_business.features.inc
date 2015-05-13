<?php
/**
 * @file
 * sugufi_business.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sugufi_business_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sugufi_business_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function sugufi_business_flag_default_flags() {
  $flags = array();
  // Exported flag: "add to favorite".
  $flags['add_to_favorite'] = array(
    'entity_type' => 'node',
    'title' => 'add to favorite',
    'global' => 0,
    'types' => array(
      0 => 'business',
    ),
    'flag_short' => 'Add to favorites',
    'flag_long' => '',
    'flag_message' => 'This business was added to your favorite',
    'unflag_short' => 'Remove from favorites',
    'unflag_long' => '',
    'unflag_message' => 'This business was removed from your favorites',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'sugufi_business',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function sugufi_business_node_info() {
  $items = array(
    'business' => array(
      'name' => t('Business'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
