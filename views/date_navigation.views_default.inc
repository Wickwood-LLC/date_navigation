<?php
/**
 * @file
 * Default views for date_navigation module.
 */

/**
 * Implements hook_views_default_views().
 */
function date_navigation_views_default_views() {
	$view = new view();
	$view->name = 'date_navigation';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'node';
	$view->human_name = 'Date Navigation';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'Date Navigation';
	$handler->display->display_options['use_ajax'] = TRUE;
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'perm';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['query']['options']['query_comment'] = FALSE;
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['pager']['options']['offset'] = '0';
	$handler->display->display_options['pager']['options']['id'] = '0';
	$handler->display->display_options['pager']['options']['quantity'] = '9';
	$handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
	$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Number of items to show per page';
	$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
	$handler->display->display_options['style_plugin'] = 'default';
	$handler->display->display_options['row_plugin'] = 'node';
	/* Field: Content: Title */
	$handler->display->display_options['fields']['title']['id'] = 'title';
	$handler->display->display_options['fields']['title']['table'] = 'node';
	$handler->display->display_options['fields']['title']['field'] = 'title';
	$handler->display->display_options['fields']['title']['label'] = '';
	$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
	$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
	
	if (module_exists('publication_date')) {
		/* Sort criterion: Content: Published at */
		$handler->display->display_options['sorts']['published_at']['id'] = 'published_at';
		$handler->display->display_options['sorts']['published_at']['table'] = 'publication_date';
		$handler->display->display_options['sorts']['published_at']['field'] = 'published_at';
		$handler->display->display_options['sorts']['published_at']['order'] = 'DESC';
		/* Contextual filter: Content: Published year */
		$handler->display->display_options['arguments']['published_at_year']['id'] = 'published_at_year';
		$handler->display->display_options['arguments']['published_at_year']['table'] = 'publication_date';
		$handler->display->display_options['arguments']['published_at_year']['field'] = 'published_at_year';
		$handler->display->display_options['arguments']['published_at_year']['default_argument_type'] = 'fixed';
		$handler->display->display_options['arguments']['published_at_year']['summary']['number_of_records'] = '0';
		$handler->display->display_options['arguments']['published_at_year']['summary']['format'] = 'default_summary';
		$handler->display->display_options['arguments']['published_at_year']['summary_options']['items_per_page'] = '10';
		/* Contextual filter: Content: Published month */
		$handler->display->display_options['arguments']['published_at_month']['id'] = 'published_at_month';
		$handler->display->display_options['arguments']['published_at_month']['table'] = 'publication_date';
		$handler->display->display_options['arguments']['published_at_month']['field'] = 'published_at_month';
		$handler->display->display_options['arguments']['published_at_month']['default_argument_type'] = 'fixed';
		$handler->display->display_options['arguments']['published_at_month']['summary']['number_of_records'] = '0';
		$handler->display->display_options['arguments']['published_at_month']['summary']['format'] = 'default_summary';
		$handler->display->display_options['arguments']['published_at_month']['summary_options']['items_per_page'] = '10';
		/* Contextual filter: Content: Published day */
		$handler->display->display_options['arguments']['published_at_day']['id'] = 'published_at_day';
		$handler->display->display_options['arguments']['published_at_day']['table'] = 'publication_date';
		$handler->display->display_options['arguments']['published_at_day']['field'] = 'published_at_day';
		$handler->display->display_options['arguments']['published_at_day']['default_argument_type'] = 'fixed';
		$handler->display->display_options['arguments']['published_at_day']['summary']['number_of_records'] = '0';
		$handler->display->display_options['arguments']['published_at_day']['summary']['format'] = 'default_summary';
		$handler->display->display_options['arguments']['published_at_day']['summary_options']['items_per_page'] = '10';
	} else {
		/* Sort criterion: Content: Post date */
		$handler->display->display_options['sorts']['created']['id'] = 'created';
		$handler->display->display_options['sorts']['created']['table'] = 'node';
		$handler->display->display_options['sorts']['created']['field'] = 'created';
		$handler->display->display_options['sorts']['created']['order'] = 'DESC';
		/* Contextual filter: Content: Created year */
		$handler->display->display_options['arguments']['created_year']['id'] = 'created_year';
		$handler->display->display_options['arguments']['created_year']['table'] = 'node';
		$handler->display->display_options['arguments']['created_year']['field'] = 'created_year';
		$handler->display->display_options['arguments']['created_year']['default_argument_type'] = 'fixed';
		$handler->display->display_options['arguments']['created_year']['default_argument_skip_url'] = 0;
		$handler->display->display_options['arguments']['created_year']['summary']['number_of_records'] = '0';
		$handler->display->display_options['arguments']['created_year']['summary']['format'] = 'default_summary';
		$handler->display->display_options['arguments']['created_year']['summary_options']['items_per_page'] = '10';
		/* Contextual filter: Content: Created month */
		$handler->display->display_options['arguments']['created_month']['id'] = 'created_month';
		$handler->display->display_options['arguments']['created_month']['table'] = 'node';
		$handler->display->display_options['arguments']['created_month']['field'] = 'created_month';
		$handler->display->display_options['arguments']['created_month']['default_argument_type'] = 'fixed';
		$handler->display->display_options['arguments']['created_month']['default_argument_skip_url'] = 0;
		$handler->display->display_options['arguments']['created_month']['summary']['number_of_records'] = '0';
		$handler->display->display_options['arguments']['created_month']['summary']['format'] = 'default_summary';
		$handler->display->display_options['arguments']['created_month']['summary_options']['items_per_page'] = '10';
		/* Contextual filter: Content: Created day */
		$handler->display->display_options['arguments']['created_day']['id'] = 'created_day';
		$handler->display->display_options['arguments']['created_day']['table'] = 'node';
		$handler->display->display_options['arguments']['created_day']['field'] = 'created_day';
		$handler->display->display_options['arguments']['created_day']['default_argument_type'] = 'fixed';
		$handler->display->display_options['arguments']['created_day']['summary']['number_of_records'] = '0';
		$handler->display->display_options['arguments']['created_day']['summary']['format'] = 'default_summary';
		$handler->display->display_options['arguments']['created_day']['summary_options']['items_per_page'] = '10';
	}
	
	/* Filter criterion: Content: Published */
	$handler->display->display_options['filters']['status']['id'] = 'status';
	$handler->display->display_options['filters']['status']['table'] = 'node';
	$handler->display->display_options['filters']['status']['field'] = 'status';
	$handler->display->display_options['filters']['status']['value'] = 1;
	$handler->display->display_options['filters']['status']['group'] = 1;
	$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE; 
  
  if (module_exists('locale')) {
    /* Filter criterion: Content translation: Language */
    $handler->display->display_options['filters']['language']['id'] = 'language';
    $handler->display->display_options['filters']['language']['table'] = 'node';
    $handler->display->display_options['filters']['language']['field'] = 'language';
    $handler->display->display_options['filters']['language']['value'] = array(
      '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    );
  }
	
	/* Display: Articles View Page */
	$handler = $view->new_display('page', 'Articles View Page', 'page');
	$handler->display->display_options['defaults']['title'] = FALSE;
	$handler->display->display_options['title'] = 'Articles';
	$handler->display->display_options['display_description'] = 'Display a view content type Article';
	$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
	$handler->display->display_options['defaults']['filter_groups'] = FALSE;
	$handler->display->display_options['defaults']['filters'] = FALSE;
	/* Filter criterion: Content: Published */
	$handler->display->display_options['filters']['status']['id'] = 'status';
	$handler->display->display_options['filters']['status']['table'] = 'node';
	$handler->display->display_options['filters']['status']['field'] = 'status';
	$handler->display->display_options['filters']['status']['value'] = 1;
	$handler->display->display_options['filters']['status']['group'] = 1;
	$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
	/* Filter criterion: Content: Type */
	$handler->display->display_options['filters']['type']['id'] = 'type';
	$handler->display->display_options['filters']['type']['table'] = 'node';
	$handler->display->display_options['filters']['type']['field'] = 'type';
	$handler->display->display_options['filters']['type']['value'] = array(
		'article' => 'article',
	);
	$handler->display->display_options['path'] = 'articles';
	$handler->display->display_options['menu']['type'] = 'normal';
	$handler->display->display_options['menu']['title'] = 'Articles';
	$handler->display->display_options['menu']['description'] = 'Articles listed by of publication date.';
	$handler->display->display_options['menu']['weight'] = '0';
	$handler->display->display_options['menu']['context'] = 0;

	/* Display: Pages View page */
	$handler = $view->new_display('page', 'Pages View page', 'page_1');
	$handler->display->display_options['defaults']['title'] = FALSE;
	$handler->display->display_options['title'] = 'Pages';
	$handler->display->display_options['display_description'] = 'Display a view content type Page';
	$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
	$handler->display->display_options['defaults']['filter_groups'] = FALSE;
	$handler->display->display_options['defaults']['filters'] = FALSE;
	/* Filter criterion: Content: Published */
	$handler->display->display_options['filters']['status']['id'] = 'status';
	$handler->display->display_options['filters']['status']['table'] = 'node';
	$handler->display->display_options['filters']['status']['field'] = 'status';
	$handler->display->display_options['filters']['status']['value'] = 1;
	$handler->display->display_options['filters']['status']['group'] = 1;
	$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
	/* Filter criterion: Content: Type */
	$handler->display->display_options['filters']['type']['id'] = 'type';
	$handler->display->display_options['filters']['type']['table'] = 'node';
	$handler->display->display_options['filters']['type']['field'] = 'type';
	$handler->display->display_options['filters']['type']['value'] = array(
		'page' => 'page',
	);
	$handler->display->display_options['path'] = 'pages';
	$handler->display->display_options['menu']['type'] = 'normal';
	$handler->display->display_options['menu']['title'] = 'Pages';
	$handler->display->display_options['menu']['description'] = 'Pages listed by of publication date.';
	$handler->display->display_options['menu']['weight'] = '0';
	$handler->display->display_options['menu']['context'] = 0;

  $views[$view->name] = $view;
  return $views;
}
