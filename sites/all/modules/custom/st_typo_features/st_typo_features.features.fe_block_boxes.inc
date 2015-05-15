<?php
/**
 * @file
 * st_typo_features.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function st_typo_features_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Custom Block - Contact form';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'contact_form';
  $fe_block_boxes->body = '<div class="container">
	<div class="title-section">
		<h1 class="typo">CONTACT</h1>
		<span class="underline"></span>
		<p>Aliquam sit amet gravida tellus. Curabitur vel consectetur magna, a pellentesque lacus. Nam placerat eros nec tortor gravida, non pulvinar ligula volutpat. Vivamus eu lobortis velit. Nulla vel odio vel augue varius lacinia nec ut mauris. Vestibulum eu fermentum arcu, et scelerisque elit.</p>
	</div>
	<div class="contact-box">
		<div class="row">
			<div class="col-md-4">
				<h2>TYPO CREATIVE AGENCY</h2>
				<p>We always look forward to meet new awesome people and discuss brilliant project ideas. Come visit us!</p>
				<ul class="info">
					<li class="adress">ADRESS:</li>
					<li>18901890 Web Avenue, Suite #97-51, Office 14<br>Almaty, Kazakhstan, 050000</li>
					<li class="fax">PHONE/FAX:</li>
					<li>+77017578779</li>	
					<li class="email">EMAIL:</li>
					<li><a href="#">info@companyname.com</a></li>		
				</ul>
			</div>

			<div class="col-md-8">
				<div class="contact-form">
					<h2>DROP US A LETTER</h2>
					<div class="drop-box">
						<?php
							if(!function_exists(\'contact_site_page\')) {
							  require_once drupal_get_path(\'module\', \'contact\').\'/contact.pages.inc\';
							  $output = drupal_get_form(\'contact_site_form\');
							  print drupal_render($output);
							}
						?>
					</div> <!-- end drop-box-->					
				</div><!-- end contact-form-->
			</div>						  			
		</div> <!-- end row-->

	</div> <!-- end contact-box-->

</div>
<!-- end contact section -->

<div class="section">
	<div id="map-section">
	</div>
</div>';

  $export['contact_form'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Copyright';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'coppyright';
  $fe_block_boxes->body = '<div class="col-md-3">
	<a class="footer-logo" href="/"><img src="<?php print theme_get_setting(\'logo\');  ?>" alt="" ></a>
</div>
<div class="col-md-6">
	<p class="copyright-line"><span>made by Nunforest, all rights reserved</span></p>
</div>
<div class="col-md-3">
	<ul class="footer-icons">
		<li><a class="twitter" href="#"><i class="fa fa-twitter"></i></a></li>
		<li><a class="pinterest" href="#"><i class="fa fa-pinterest"></i></a></li>					
		<li><a class="dribble" href="#"><i class="fa fa-dribbble"></i></a></li>					
		<li><a class="google" href="#"><i class="fa fa-skype"></i></a></li>					
	</ul>
</div>';

  $export['coppyright'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Custom Block - footer';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'footer';
  $fe_block_boxes->body = '<div class="container">
	<h2>LET\'S GET SOCIAL</h2>
	<ul class="social-icons">
		<li class="facebook"><a href="#"><i class="fa fa-facebook"></i></a></li>
		<li class="twitter"><a href="#"><i class="fa fa-twitter"></i></a></li>
		<li class="behance"><a href="#"><i class="fa fa-behance"></i></a></li>
		<li class="linkedin"><a href="#"><i class="fa fa-linkedin"></i></a></li>
		<li class="dribble"><a href="#"><i class="fa fa-dribbble"></i></a></li>
	</ul>
</div>

<span class="social-line"></span>
<p>by Nunforest for Themeforest</p>';

  $export['footer'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Service';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'service';
  $fe_block_boxes->body = '<!-- services section -->
<div class="section">
<div>
<div class="container">
<div class="title-section">
<h1 class="typo">SERVICES</h1>
<span class="underline">&nbsp;</span>

<p>Aliquam sit amet gravida tellus. Curabitur vel consectetur magna, a pellentesque lacus. Nam placerat eros nec tortor gravida, non pulvinar ligula volutpat. Vivamus eu lobortis velit. Nulla vel odio vel augue varius lacinia nec ut mauris. Vestibulum eu fermentum arcu, et scelerisque elit.</p>
</div>

<div class="services-box">
<div class="row">
<div class="col-md-5">
<div class="user-box">
<div class="image-post"><i class="fa fa-thumbs-up">&nbsp;</i></div>

<div class="services-post">
<h3>USER EXPERIENCE</h3>

<p>Quisque luctus luctus risus id euismod. Quisque at sem congue, malesuada neque nec, fringilla arcu.</p>
</div>
</div>

<div class="user-box">
<div class="image-post"><i class="fa fa-trophy">&nbsp;</i></div>

<div class="services-post">
<h3>IOS DEVELOPMENT</h3>

<p>Nunc pretium enim ac elit auctor pretium eget a quam. Etiam tincidunt auctor. Morbi fringilla, magna non mollis.</p>
</div>
</div>

<div class="user-box">
<div class="image-post"><i class="fa fa-truck">&nbsp;</i></div>

<div class="services-post">
<h3>WEB DESIGN</h3>

<p>Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.</p>
</div>
</div>
</div>

<div class="col-md-2">
<div class="mid-post"><img alt="" src="/sites/default/files/iphone.png" /></div>
</div>

<div class="col-md-5">
<div class="user-box">
<div class="image-post2"><i class="fa fa-paper-plane-o">&nbsp;</i></div>

<div class="services-post2">
<h3>SOCIAL MEDIA</h3>

<p>Curabitur sollicitudin gravida mollis. Morbi eu urna. Donec tincidunt magna nibh, ut imperdiet metus vitae.</p>
</div>
</div>

<div class="user-box">
<div class="image-post2"><i class="fa fa-cog">&nbsp;</i></div>

<div class="services-post2">
<h3>ANDROID DEVELOPMENT</h3>

<p>Donec vel ipsum mi. Quisque consequat dignissim tellus, at egestas neque hendrerit at. Nunc blandit convallis enim.</p>
</div>
</div>

<div class="user-box">
<div class="image-post2"><i class="fa fa-share-alt-square">&nbsp;</i></div>

<div class="services-post2">
<h3>CLIENT SUPPORT</h3>

<p>Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.</p>
</div>
</div>
</div>
</div>
</div>
</div>
</div>
</div>
<!-- end services section -->';

  $export['service'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Video showcase';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'video_showcase';
  $fe_block_boxes->body = '<!-- Showcase section -->
<div class="section">
<div id="showcase-section"><!-- video background tags -->
<div class="container">
<div class="title-section">
<h1>VIDEO SHOWCASE</h1>

<p>Aliquam sit amet gravida tellus. Curabitur vel consectetur magna, a pellentesque lacus. Nam placerat eros nec tortor gravida, non pulvinar ligula volutpat. Vivamus eu lobortis velit. Nulla vel odio vel augue varius lacinia nec ut mauris. Vestibulum eu fermentum arcu, et scelerisque elit.</p>
<a class="play-button" href="#"><i class="fa fa-play">&nbsp;</i><i class="fa fa-pause">&nbsp;</i></a></div>
</div>
</div>
</div>
<!-- end Showcase section -->';

  $export['video_showcase'] = $fe_block_boxes;

  return $export;
}
