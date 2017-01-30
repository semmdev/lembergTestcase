<?php
/**
 * Implements hook_views_default_views().
 */
function test_module_views_default_views() {
  $path = '/views/default_views/';
  $extension = '/\.default/';
  $files = file_scan_directory(drupal_get_path('module', 'test_module') . $path, $extension);

  $views = array();

  foreach ($files as $absolute => $file) {
    $func = FALSE;
    $view = NULL;

    require_once $absolute;
    $func = $file->name;

    if (function_exists($func)) {
      $view = $func();
      $views[$view->name] = $view;
    }
  }
  return $views;
}