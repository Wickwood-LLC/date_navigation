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

    foreach ($year['months'] as $monthkey => $monthvalue) {
      $item['children'][$monthkey] = array(
        'data' => t('!month [@count]', array('!month' => l($monthvalue['text'], $monthvalue['url']), '@count' => $monthvalue['count'])),
        'children' => array(),
      );
      
      foreach ($monthvalue['days'] as $daykey => $dayvalue) {
				$item['children'][$monthkey]['children'][] = array(
					'data' => t('!day [@count]', array('!day' => l($daykey, $dayvalue['url']), '@count' => $dayvalue['count'])),
				);
    	}
    }
    $items[] = $item;
  }
  return theme('item_list', array(
    'items' => $items,
  ));
}
