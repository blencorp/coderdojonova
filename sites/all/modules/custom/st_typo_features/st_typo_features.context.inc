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
          'region' => 'home_section',
          'weight' => '-10',
        ),
        'views-our_work-block' => array(
          'module' => 'views',
          'delta' => 'our_work-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-portfolio-block_1' => array(
          'module' => 'views',
          'delta' => 'portfolio-block_1',
          'region' => 'content',
          'weight' => '-9',
        ),
        'block-12' => array(
          'module' => 'block',
          'delta' => '12',
          'region' => 'content',
          'weight' => '-8',
        ),
        'block-13' => array(
          'module' => 'block',
          'delta' => '13',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-portfolio-block' => array(
          'module' => 'views',
          'delta' => 'portfolio-block',
          'region' => 'content',
          'weight' => '-6',
        ),
        'views-testimonial-block' => array(
          'module' => 'views',
          'delta' => 'testimonial-block',
          'region' => 'content',
          'weight' => '-5',
        ),
        'views-blog-block_2' => array(
          'module' => 'views',
          'delta' => 'blog-block_2',
          'region' => 'content',
          'weight' => '-4',
        ),
        'views-client-block' => array(
          'module' => 'views',
          'delta' => 'client-block',
          'region' => 'content',
          'weight' => '-3',
        ),
        'views-pricing_table-block' => array(
          'module' => 'views',
          'delta' => 'pricing_table-block',
          'region' => 'content',
          'weight' => '-2',
        ),
        'views-team-block' => array(
          'module' => 'views',
          'delta' => 'team-block',
          'region' => 'content',
          'weight' => '-1',
        ),
        'block-9' => array(
          'module' => 'block',
          'delta' => '9',
          'region' => 'content',
          'weight' => '0',
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
