<?php
/**
 * @file
 * sugufi_search_db.features.inc
 */

/**
 * Implements hook_default_search_api_server().
 */
function sugufi_search_db_default_search_api_server() {
  $items = array();
  $items['mysql'] = entity_import('search_api_server', '{
    "name" : "Mysql",
    "machine_name" : "mysql",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 0,
      "indexes" : { "business_index" : {
          "nid" : {
            "table" : "search_api_db_business_index",
            "column" : "nid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_business_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_business_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_business_category" : {
            "table" : "search_api_db_business_index_field_business_category",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_business_phone" : {
            "table" : "search_api_db_business_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_business_email" : {
            "table" : "search_api_db_business_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_business_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_image:file" : {
            "table" : "search_api_db_business_index",
            "column" : "field_image_file",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_image:alt" : {
            "table" : "search_api_db_business_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_business_website:title" : {
            "table" : "search_api_db_business_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_business_website:url" : {
            "table" : "search_api_db_business_index",
            "column" : "field_business_website_url",
            "type" : "uri",
            "boost" : "1.0"
          },
          "field_business_social_link:title" : {
            "table" : "search_api_db_business_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_business_social_link:url" : {
            "table" : "search_api_db_business_index_field_business_social_link_url",
            "column" : "value",
            "type" : "list\\u003Curi\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
