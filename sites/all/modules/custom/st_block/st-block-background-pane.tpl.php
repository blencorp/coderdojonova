<?php
/**
 * @file panels-pane.tpl.php
 * Main panel pane template
 *
 * Variables available:
 * - $pane->type: the content type inside this pane
 * - $pane->subtype: The subtype, if applicable. If a view it will be the
 *   view name; if a node it will be the nid, etc.
 * - $title: The title of the content
 * - $content: The actual content
 * - $links: Any links associated with the content
 * - $more: An optional 'more' link (destination only)
 * - $admin_links: Administrative links associated with the content
 * - $feeds: Any feed icons or associated with the content
 * - $display: The complete panels display object containing all kinds of
 *   data including the contexts and all of the other panes being displayed.
 */
?>
<?php  
  $block_parts = explode('-', $pane->subtype);
  $module = $block_parts[0];
  unset($block_parts[0]);
  $block_delta = implode('-', $block_parts);
  $block = block_load($module, $block_delta);
  $background_style = '';
  if($block->background_type == 'image' && isset($block->background_image)) {  
    $bg_image = file_load($block->background_image);
    if ($bg_image)   {
      $background_image_uri = file_load($block->background_image)->uri;
      $background_image_path = file_create_url($background_image_uri);
      $background_style = 'style="background:url(' . $background_image_path . ');"';
    }    
  }
  
  if (isset($block->st_block_id) && $block->st_block_id != '') {
    $id = 'id = "' . $block->st_block_id . '"';
  }

?>

<?php if ($pane_prefix): ?>
  <?php print $pane_prefix; ?>
<?php endif; ?>
<div <?php print $background_style; ?> class="<?php print $classes; ?>" <?php print $id; ?> <?php print $attributes; ?>>
  <?php if($block->background_type == 'video'): ?>
    <div class="background">
     <?php print $block->video_embed; ?>
    </div>
  <?php endif; ?> 
  <div class="block-content">
    <?php if ($admin_links): ?>
      <?php print $admin_links; ?>
    <?php endif; ?>

    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
      <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <?php if ($feeds): ?>
      <div class="feed">
        <?php print $feeds; ?>
      </div>
    <?php endif; ?>

    <div class="pane-content">
      <?php print render($content); ?>
    </div>

    <?php if ($links): ?>
      <div class="links">
        <?php print $links; ?>
      </div>
    <?php endif; ?>

    <?php if ($more): ?>
      <div class="more-link">
        <?php print $more; ?>
      </div>
    <?php endif; ?>
  </div>
</div>
<?php if ($pane_suffix): ?>
  <?php print $pane_suffix; ?>
<?php endif; ?>