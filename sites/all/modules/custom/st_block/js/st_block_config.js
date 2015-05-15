var $ = jQuery.noConflict();

$(document).ready(function($) {
	"use strict";

	background_check();
	$("input[name='background_type']").change(function() {
		background_check();
	});
});

function background_check() {
	var background_type = $('input[name=background_type]:checked').val();
	switch (background_type) {
		case '':
			$('.form-item-video-embed').hide();
			$('input[name=block-img-background').hide();
			$('.form-item-stellar-ratio').hide();
			$('#edit-background-image-ajax-wrapper').hide();
			break;

		case 'video':
			$('.form-item-video-embed').show();
			$('input[name=block-img-background').hide();
			$('.form-item-stellar-ratio').hide();
			$('#edit-background-image-ajax-wrapper').hide();
			break;

		case 'image':
			$('.form-item-video-embed').hide();
			$('input[name=block-img-background').show();
			$('.form-item-stellar-ratio').show();
			$('#edit-background-image-ajax-wrapper').show();
			break;
	}
}