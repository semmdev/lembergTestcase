<?php
/**
 * @file
 * Provides custom Panels pane.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Last 4 nodes'),
  'description' => t('Display block of teaser for last 4 nodes'),
  'category' => t('Custom Panes'),
  'render callback' => 'test_module_last_nodes_render',
  'defaults' => array(),
);

/**
 * Render the panel.
 */
function test_module_last_nodes_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $content = '';
  $query = new EntityFieldQuery();
  $entities = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'test_ct')
    ->propertyOrderBy("created", "DESC")
    ->range(0, 4)
    ->execute();
  if (!empty($entities['node'])) {
    foreach ($entities['node'] as $obj) {
      $node = node_load($obj->nid);
      $view = node_view($node, 'teaser');
      $content .= drupal_render($view);
    }
  }
  $block->content = $content;
  return $block;
}
