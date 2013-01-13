<?php
/**
 * @file
 * Theme functions for the Date Navigation module.
 */


/**
 * Theme handler for theme('date_navigation_archive').
 */
function theme_date_navigation_archive($element) {
  $items = array();
  $items[] = $element['element']['show_all_link'];

  $archive = $element['element']['archive'];

  foreach ($archive as $year) {
    $item = array(
      'data' => t('!year [@count]', array('!year' => l($year['text'], $year['url']), '@count' => $year['count'])),
      'children' => array(),
    );

    foreach ($year['months'] as $month) {
      $item['children'][] = array(
        'data' => t('!month [@count]', array('!month' => l($month['text'], $month['url']), '@count' => $month['count'])),
      );
    }
    $items[] = $item;
  }

  return theme('item_list', array(
    'items' => $items,
  ));
}
