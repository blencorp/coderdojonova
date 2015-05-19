<?php
/**
 * @file
 * st_typo_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function st_typo_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  if ($module == "taxonomy_display" && $api == "taxonomy_display") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function st_typo_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function st_typo_features_flag_default_flags() {
  $flags = array();
  // Exported flag: "Like".
  $flags['like'] = array(
    'entity_type' => 'node',
    'title' => 'Like',
    'global' => 0,
    'types' => array(
      0 => 'blog',
    ),
    'flag_short' => 'Like',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unlike',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'st_typo_features',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function st_typo_features_image_default_styles() {
  $styles = array();

  // Exported image style: blog_369x200_.
  $styles['blog_369x200_'] = array(
    'name' => 'blog_369x200_',
    'label' => 'Blog(369x200)',
    'effects' => array(
      5 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 369,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: client_image.
  $styles['client_image'] = array(
    'name' => 'client_image',
    'label' => 'client image',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 228,
          'height' => 89,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: md_slider_1_thumb.
  $styles['md_slider_1_thumb'] = array(
    'name' => 'md_slider_1_thumb',
    'label' => 'md_slider_1_thumb',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 75,
          'scaleup' => FALSE,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: md_slider_2_thumb.
  $styles['md_slider_2_thumb'] = array(
    'name' => 'md_slider_2_thumb',
    'label' => 'md_slider_2_thumb',
    'effects' => array(
      6 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 75,
          'scaleup' => FALSE,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: md_slider_3_thumb.
  $styles['md_slider_3_thumb'] = array(
    'name' => 'md_slider_3_thumb',
    'label' => 'md_slider_3_thumb',
    'effects' => array(
      7 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 75,
          'scaleup' => FALSE,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: member.
  $styles['member'] = array(
    'name' => 'member',
    'label' => 'Member',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 270,
          'height' => 270,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: portfolio_image.
  $styles['portfolio_image'] = array(
    'name' => 'portfolio_image',
    'label' => 'Portfolio image',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_install().
 */
function st_typo_features_install() {
$sliders = array(
  1 => array(
    'slid' => 1,
    'title' => 'Banner slideshow',
    'description' => '',
    'machine_name' => 'banner-slideshow',
    'settings' => 'a:31:{s:10:"full_width";i:1;s:11:"full_height";i:0;s:5:"width";s:4:"1302";s:6:"height";s:3:"420";s:11:"touch_swipe";i:1;s:10:"responsive";i:1;s:8:"videobox";i:0;s:4:"loop";i:1;s:10:"loadingbar";s:4:"none";s:12:"bar_position";s:6:"bottom";s:21:"show_next_prev_button";i:1;s:9:"auto_play";i:1;s:11:"pause_hover";i:0;s:11:"show_bullet";i:1;s:15:"bullet_position";s:1:"2";s:14:"show_thumbnail";i:0;s:18:"thumbnail_position";s:1:"1";s:12:"border_style";s:1:"0";s:16:"dropshadow_style";s:1:"0";s:9:"animation";s:4:"fade";s:5:"delay";s:4:"8000";s:9:"transtime";s:3:"800";s:11:"thumb_width";s:3:"100";s:12:"thumb_height";s:2:"75";s:18:"create_bg_imgstyle";i:0;s:10:"dmf_google";s:134:"http://fonts.googleapis.com/css?family=Roboto:400,100,100italic,300,300italic,400italic,500,500italic,700,700italic|Montserrat:400,700";s:15:"enable_font_css";i:1;s:17:"generate_css_file";i:0;s:8:"on_start";s:0:"";s:6:"on_end";s:0:"";s:11:"color_saved";s:13:"ff9900,CC0000";}',
  ),
  2 => array(
    'slid' => 2,
    'title' => 'Small banner slideshow',
    'description' => '',
    'machine_name' => 'md-slider-549c24fb867ef',
    'settings' => 'a:31:{s:10:"full_width";i:1;s:11:"full_height";i:0;s:5:"width";s:4:"1302";s:6:"height";s:3:"580";s:11:"touch_swipe";i:1;s:10:"responsive";i:1;s:8:"videobox";i:0;s:4:"loop";i:1;s:10:"loadingbar";s:4:"none";s:12:"bar_position";s:6:"bottom";s:21:"show_next_prev_button";i:1;s:9:"auto_play";i:1;s:11:"pause_hover";i:0;s:11:"show_bullet";i:0;s:15:"bullet_position";s:1:"5";s:14:"show_thumbnail";i:0;s:18:"thumbnail_position";s:1:"1";s:12:"border_style";s:1:"0";s:16:"dropshadow_style";s:1:"0";s:9:"animation";s:4:"fade";s:5:"delay";s:4:"8000";s:9:"transtime";s:3:"800";s:11:"thumb_width";s:3:"100";s:12:"thumb_height";s:2:"75";s:18:"create_bg_imgstyle";i:0;s:10:"dmf_google";s:134:"http://fonts.googleapis.com/css?family=Roboto:400,100,100italic,300,300italic,400italic,500,500italic,700,700italic|Montserrat:400,700";s:15:"enable_font_css";i:1;s:17:"generate_css_file";i:0;s:8:"on_start";s:0:"";s:6:"on_end";s:0:"";s:11:"color_saved";s:13:"ff9900,CC0000";}',
  ),
  3 => array(
    'slid' => 3,
    'title' => 'Banner slideshow video background',
    'description' => '',
    'machine_name' => 'md-slider-549c2aeaaf9ab',
    'settings' => 'a:31:{s:10:"full_width";i:1;s:11:"full_height";i:1;s:5:"width";s:4:"1302";s:6:"height";s:3:"680";s:11:"touch_swipe";i:1;s:10:"responsive";i:1;s:8:"videobox";i:0;s:4:"loop";i:1;s:10:"loadingbar";s:4:"none";s:12:"bar_position";s:6:"bottom";s:21:"show_next_prev_button";i:1;s:9:"auto_play";i:1;s:11:"pause_hover";i:0;s:11:"show_bullet";i:0;s:15:"bullet_position";s:1:"5";s:14:"show_thumbnail";i:0;s:18:"thumbnail_position";s:1:"1";s:12:"border_style";s:1:"0";s:16:"dropshadow_style";s:1:"0";s:9:"animation";s:4:"fade";s:5:"delay";s:4:"8000";s:9:"transtime";s:3:"800";s:11:"thumb_width";s:3:"100";s:12:"thumb_height";s:2:"75";s:18:"create_bg_imgstyle";i:0;s:10:"dmf_google";s:134:"http://fonts.googleapis.com/css?family=Roboto:400,100,100italic,300,300italic,400italic,500,500italic,700,700italic|Montserrat:400,700";s:15:"enable_font_css";i:1;s:17:"generate_css_file";i:0;s:8:"on_start";s:0:"";s:6:"on_end";s:0:"";s:11:"color_saved";s:13:"ff9900,CC0000";}',
  ),
);
foreach ($sliders as $slider) {
	$slider = (object)$slider;
	$slider = _md_slider_recast('MDSlider',$slider);
	$slider->slid = NULL;

	if (!MDSlider::get_by_machine_name($slider->machine_name))
		$slider->save();
}
}

/**
 * Implements hook_node_info().
 */
function st_typo_features_node_info() {
  $items = array(
    'about' => array(
      'name' => t('About'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'client' => array(
      'name' => t('Client'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'member' => array(
      'name' => t('Member'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'portfolio' => array(
      'name' => t('Portfolio'),
      'base' => 'node_content',
      'description' => t('Portfolio'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'pricing' => array(
      'name' => t('Pricing'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'service' => array(
      'name' => t('Service'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'testimonial' => array(
      'name' => t('Testimonial'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
