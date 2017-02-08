<?php

//class WebservicesMyNodeController extends WebservicesEntityController {
//  const ENTITY_TYPE = 'my_node';
//
//  protected function index() {
//    $query = db_select('node', 'n');
//    $nids = $query
//      ->fields('n', array('nid'))
//      ->addTag('node_access')
//      ->execute()
//      ->fetchCol();
//    $nodes = array_values(node_load_multiple($nids));
//
//    return $nodes;
//  }
//
//  public function access() {
//    switch ($this->method) {
//      case 'index':
//        return 'access content';
//      default:
//        return FALSE;
//    }
//  }
//}

