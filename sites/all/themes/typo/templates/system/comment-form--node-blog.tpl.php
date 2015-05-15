<?php
	hide($form['author']);	
?>
<div class="post-title">
	<h3><?php print t('Leave a Comment'); ?></h3>
	<span class="underline"></span>
</div>
<?php print render($form['subject']); ?>
<?php print render($form['comment_body']); ?>
<div class="submit-area">
	<div class="actions">
		<?php print render($form['actions']); ?>							
	</div>
</div>
<?php print drupal_render_children($form); ?>