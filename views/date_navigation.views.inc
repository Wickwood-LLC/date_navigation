<?php
/**
 * @file
 * Provide function to alter views query.
 */

/**
 * Implements hook_views_query_alter().
 */
function date_navigation_views_query_alter(&$view, &$query) {
  $driver = db_driver();
  if ($view->name == 'date_navigation' && !empty($query->where[0]['conditions'])) {
    foreach ($query->where[0]['conditions'] as $key => $condition) {

      // Alter views query for SQLite Database.
      if (is_array($condition['value']) && $driver == 'sqlite') {
        if (key($condition['value']) == ':node_created_year') {
          $query->where[0]['conditions'][$key]['field'] = "strftime('%Y', date(node.created, 'unixepoch')) = :node_created_year";
        }
        elseif (key($condition['value']) == ':node_created_month') {
          $query->where[0]['conditions'][$key]['field'] = "strftime('%m', date(node.created, 'unixepoch')) = :node_created_month";
        }
      }

      // Alter views query for custom node archive block.
      if (isset($view->args['2']) && $view->args['2'] == 'custom' && $condition['value'] == 'custom') {
        $query->where[0]['conditions'][$key]['operator'] = 'in';
        $custom_selection = variable_get('date_navigation_custom_selection', array('page'));
        foreach ($custom_selection as $custom_key => $value) {
          if ($value != '0') {
            $values[] = $value;
          }
        }
        $query->where[0]['conditions'][$key]['value'] = $values;
        $view->build_info['substitutions']['%3'] = 'Custom node';
      }
    }
    
    // Set breadcrumb and title.
    $view_base_title = $view->build_info['title'];
    $arg = explode('/', $_GET['q']);
    if(isset($arg[1])) {
    	$year = $arg[1];
    	$year_url = $arg[0]. '/' . $arg[1];
    	$view->build_info['breadcrumb'][$year_url] = $year;
    	$view->build_info['title'] = $view_base_title . ' from ' . $year;
    }
    if(isset($arg[2])) {
    	$month = date('F', mktime(0, 0, 0, $arg[2]));
    	$month_url = $arg[0] . '/' . $arg[1] . '/' . $arg[2];
    	$view->build_info['breadcrumb'][$month_url] = $month;
    	$view->build_info['title'] = $view_base_title . ' from ' . $month . ', ' . $year;
    }
  }
}