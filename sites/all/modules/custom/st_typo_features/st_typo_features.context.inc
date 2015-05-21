<?php
/**
 * @file
 * st_typo_features.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function st_typo_features_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_tag_page';
  $context->description = '';
  $context->tag = 'blog';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'tags/*' => 'tags/*',
        'blogs' => 'blogs',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-blog_categories-block' => array(
          'module' => 'views',
          'delta' => 'blog_categories-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('blog');
  $export['blog_tag_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home_page';
  $context->description = 'Home page';
  $context->tag = 'home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'md_slider-banner-slideshow' => array(
          'module' => 'md_slider',
          'delta' => 'banner-slideshow',
          'region' => 'content',
          'weight' => '-23',
        ),
        'views-class_schedule-block' => array(
          'module' => 'views',
          'delta' => 'class_schedule-block',
          'region' => 'content',
          'weight' => '-21',
        ),
        'views-first_parallax-block' => array(
          'module' => 'views',
          'delta' => 'first_parallax-block',
          'region' => 'content',
          'weight' => '-20',
        ),
        'views-blog-block_2' => array(
          'module' => 'views',
          'delta' => 'blog-block_2',
          'region' => 'content',
          'weight' => '-19',
        ),
        'views-first_parallax-block_1' => array(
          'module' => 'views',
          'delta' => 'first_parallax-block_1',
          'region' => 'content',
          'weight' => '-18',
        ),
        'views-team-block_1' => array(
          'module' => 'views',
          'delta' => 'team-block_1',
          'region' => 'content',
          'weight' => '-17',
        ),
        'views-first_parallax-block_2' => array(
          'module' => 'views',
          'delta' => 'first_parallax-block_2',
          'region' => 'content',
          'weight' => '-16',
        ),
        'views-pricing_table-block' => array(
          'module' => 'views',
          'delta' => 'pricing_table-block',
          'region' => 'content',
          'weight' => '-15',
        ),
        'block-7' => array(
          'module' => 'block',
          'delta' => '7',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home page');
  t('home');
  $export['home_page'] = $context;

  return $export;
}
