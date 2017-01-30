<?php
/**
 * Implements hook_views_default_views().
 **/
function test_module_views_default_views() {
  $files = file_scan_directory(drupal_get_path('module', 'test_module'). '/views', '/.view/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  if ($views) {
    return $views;
  }
}
