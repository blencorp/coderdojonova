<?php
/**
 * @file
 * theme-settings.php
 *
 * Provides theme settings for typo themes when admin theme is not.
 *
 * 
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function typo_form_system_theme_settings_alter(&$form, $form_state, $form_id = NULL) {
  // Alter theme settings form.
  $form['typo'] = array
    (
      '#type' => 'vertical_tabs',
      '#prefix' => '<h2><small>' . t('TYPO SETTINGS') . '</small></h2>',
      '#weight' => -8
    );
  $form['typo_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('STYLE SWITCHER'),
    '#group' => 'typo'
  );
    
  $form['typo_settings']['style_color'] = array(
    '#type' =>'select', 
    '#title' => t('Style color'),
    '#options' => array(
      'light' => t('Light'),
      'dark' => t('Dark'),          
     ),
    '#default_value' => theme_get_setting('style_color')?theme_get_setting('style_color'):'light',
  );

  return $form;
}
