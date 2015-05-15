<?php

/**
 * @file
 * template.php
 */

function typo_preprocess_page(&$variables) {

  $alias_parts = explode('/', drupal_get_path_alias());
  $theme_path = drupal_get_path('theme', 'typo');
 
  drupal_add_js('http://maps.google.com/maps/api/js?sensor=false', array('type' => 'external'));
  drupal_add_js($theme_path . '/js/gmap3.min.js');  

  if (drupal_is_front_page()) {
    drupal_add_js($theme_path . '/js/smooth-scroll.js');
    drupal_add_js($theme_path . '/js/plugins-scroll.js');    
  }

  $theme_style = theme_get_setting('style_color');

  if ($theme_style == 'dark') {
    drupal_add_css($theme_path . '/css/dark-style.css');
  }

  if (drupal_is_front_page()) {
    drupal_set_title('');
  }
}
function typo_menu_tree__primary(&$variables) {
  return '<ul class="nav navbar-nav navbar-right">' . $variables['tree'] . '</ul>';
}
function typo_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  
  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      // Generate as standard dropdown.
      $element['#title'] .= ' <span class="caret"></span>';
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;

      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
      $element['#localized_options']['attributes']['data-target'] = '#';
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
    }
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  if($element['#theme'] == 'menu_link__main_menu') {
    unset($element['#attributes']['class']);    
  }
  if ($element['#href'] == $_GET['q']) {
    $element['#localized_options']['attributes']['class'][] = 'current';
  }
  if ($node = menu_get_object()) {
    if ($node->type == 'blog' && $element['#href'] == 'blog') {        
      $element['#localized_options']['attributes']['class'][] = 'current';
    }
  }
  if (isset($element['#localized_options']['fragment']) && $element['#localized_options']['fragment'] == 'blog-section') {
    if ($node = menu_get_object()) {
      if ($node->type == 'blog') {        
        $element['#localized_options']['attributes']['class'][] = 'current';
      }
    }
    
    if ($_GET['q'] == 'blogs' || substr($_GET['q'], 0, 8) == 'taxonomy') {
      $element['#localized_options']['attributes']['class'][] = 'current';
    }
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";

}

function typo_js_alter(&$js) {
  $bootstrap_js_path = drupal_get_path('theme', 'bootstrap') . '/js/bootstrap.js';
  unset($js[$bootstrap_js_path]);   
  $isotope_js_path = drupal_get_path('module', 'views_isotope') . '/views_isotope.js';
  if (isset($js[$isotope_js_path])) {    
    unset($js[$isotope_js_path]);
    drupal_add_js(drupal_get_path('theme', 'typo') . '/js/views_isotope.js');
  } 
}

function typo_theme() {
  return array(
    'contact_site_form' => array(
      'render element' => 'form',
      'template' => 'contact-site-form',
      'path' => drupal_get_path('theme', 'typo').'/templates/system',
    ),
    'comment_form__node_blog' => array(
      'render element' => 'form',
      'template' => 'comment-form--node-blog',
      'path' => drupal_get_path('theme', 'typo').'/templates/system',
    ),
  );
}