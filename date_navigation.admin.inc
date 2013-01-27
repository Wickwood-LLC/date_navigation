<?php

/**
 * @file
 * Administrative callbacks for Date Navigation module.
 */

/**
 * Build form for Date Navigation Administration Settings
 */
function date_navigation_admin_settings() {
  // Get an array of node types with internal names as keys and
  // array('page' => ’Basic Page, 'article' => 'Articles')
  $types = node_type_get_types();
  $options['all'] = t('All Node Types');
  $options['custom'] = t('Custom Type');
  foreach ($types as $type) {
    $options[$type->type] = $type->name;
  }
  
  // Get an array of taxonomy vocabularies 
  // and terms used in those taxonomies
  $vocabularies = taxonomy_get_vocabularies();
  $taxonomy_options = array();
  $taxonomy_options_var = array();
  foreach ($vocabularies as $vocabulary) {
    $terms = taxonomy_get_tree($vocabulary->vid);
    $vocabulary_key = 'V' . $vocabulary->vid;
    $taxonomy_options[$vocabulary_key] = '<' . $vocabulary->name . '>';
    $taxonomy_options_var[$vocabulary_key] = $vocabulary->name;
    if (!empty($terms)) {
      foreach ($terms as $term) {
        $taxonomy_options['T' . $term->tid] = str_repeat('--', $term->depth) . $term->name;
        $taxonomy_options_var['T' . $term->tid] = $term->name;
      }
    }
  }
  variable_set('date_navigation_taxonomy_options', $taxonomy_options_var);

  $form['date_navigation_block_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Select the Node Types to create Date Navigation blocks for.'),
    '#options' => $options,
    '#default_value' => variable_get('date_navigation_block_types', array('article')),
    '#description' => t('A Date Navigation block will be created and listed in Administration » Structure » Blocks for each checked item.'),
  );

  unset($options['all']);
  unset($options['custom']);

  $form['date_navigation_custom_selection'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Select the Content Types to be included in that custom block.'),
    '#options' => $options,
    '#default_value' => variable_get('date_navigation_custom_selection', array()),
    '#description' => t('If you selected to create a Custom Date Navigation Block type above, select the Content Types to be included in that custom block.'),
  );
  
  $form['date_navigation_taxonomy_items'] = array(
    '#type' => 'select',
    '#title' => t('Create a Date Navigation Block based on taxonomy.'),
    '#options' => $taxonomy_options,
    '#default_value' => variable_get('date_navigation_taxonomy_items', array()),
    '#description' => t('Select taxnomy terms for which a Date Navigation Block should be created.'),
    '#multiple' => TRUE,
    '#attributes' => array('style' => 'height: 200px; width: 205px;'),
  );
  
  $form['date_navigation_items'] = array(
    '#type' => 'select',
    '#title' => t('Number of items'),
    '#options' => array(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10),
    '#default_value' => variable_get('date_navigation_items', 0),
    '#description' => t('Select the number of nodes to display in an expanded archive. Select 0 to show an unlimited number of nodes.'),
  );

  $disabled_jquerymenu = TRUE;
  $default_jquerymenu_option = t('The <a href="@jquerymenu_url" target="_blank">Jquery Menu module </a> is not installed and/or enabled.', array('@jquerymenu_url' => url('http://drupal.org/project/jquerymenu'),));
  $default_jquerymenu_option_value = FALSE;
  if (module_exists('jquerymenu')) {
    $disabled_jquerymenu = FALSE;
    $default_jquerymenu_option = t('Check this box if you want to use <a href="@jquerymenu_url" target="_blank">Jquery Menu module </a> to theme Date Navigation blocks.  We turn it on by default if when the module is enabled because we likes it. :-)', array('@jquerymenu_url' => url('http://drupal.org/project/jquerymenu'),));
    $default_jquerymenu_option_value = TRUE;
  }

  $form['date_navigation_jquerymenu'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Theme Date Navigation blocks using Jquery Menu module'),
    '#options' => array(1 => $default_jquerymenu_option),
    '#default_value' => variable_get('date_navigation_jquerymenu', array($default_jquerymenu_option_value)),
    '#disabled' => $disabled_jquerymenu,
  );
  
  return system_settings_form($form);
}
