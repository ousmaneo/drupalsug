<?php
/**
 * @file
 * sugufi_search_index.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sugufi_search_index_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_autocomplete_search().
 */
function sugufi_search_index_default_search_api_autocomplete_search() {
  $items = array();
  $items['search_api_views_business'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_business",
    "name" : "Business",
    "index_id" : "business_index",
    "type" : "search_api_views",
    "enabled" : "1",
    "options" : {
      "result count" : true,
      "fields" : [ "body:summary", "body:value", "title" ],
      "results" : 0,
      "min_length" : "1",
      "custom" : { "display" : "page" }
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function sugufi_search_index_default_search_api_index() {
  $items = array();
  $items['business_index'] = entity_import('search_api_index', '{
    "name" : "business index",
    "machine_name" : "business_index",
    "description" : null,
    "server" : "mysql",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "field_business_category" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_business_email" : { "type" : "text" },
        "field_business_phone" : { "type" : "list\\u003Ctext\\u003E" },
        "field_business_social_link:title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_business_social_link:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_business_website:title" : { "type" : "text" },
        "field_business_website:url" : { "type" : "uri" },
        "field_image:alt" : { "type" : "text" },
        "field_image:file" : { "type" : "integer", "entity_type" : "file" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
