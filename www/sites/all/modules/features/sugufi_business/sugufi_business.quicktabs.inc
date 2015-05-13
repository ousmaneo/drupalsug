<?php
/**
 * @file
 * sugufi_business.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function sugufi_business_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'user_profile_tab';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 999999;
  $quicktabs->title = 'user profile tab';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'favorite_business',
      'display' => 'page',
      'args' => '',
      'title' => 'Favorite business',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'rated_business',
      'display' => 'page_3',
      'args' => '',
      'title' => 'Rated business',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'rated_business',
      'display' => 'page_1',
      'args' => '',
      'title' => 'Most rated',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Favorite business');
  t('Most rated');
  t('Rated business');
  t('user profile tab');

  $export['user_profile_tab'] = $quicktabs;

  return $export;
}
