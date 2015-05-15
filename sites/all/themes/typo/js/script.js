/*jshint jquery:true */
/*global $:true */

var $ = jQuery.noConflict();

$(document).ready(function($) {
	"use strict";

	/* global google: false */

	/*-------------------------------------------------*/
	/* =  portfolio isotope
	/*-------------------------------------------------*/	
	var winDow = $(window);
	// Needed variables
	var $container=$('#isotope-container');
	var $filter=$('#filters');

	try{
		$container.imagesLoaded( function(){
			$container.show();				

			$('.triggerAnimation').waypoint(function() {
				var animation = $(this).attr('data-animate');
				$(this).css('opacity', '');
				$(this).addClass("animated " + animation);

			},
				{
					offset: '70%',
					triggerOnce: true
				}
			);

		});
	} catch(err) {
	}

	moveNavigationOwlCarousel('.view-portfolio.container', '#featured-section');
	moveNavigationOwlCarousel('.view-client', '#clients-section');
	moveNavigationOwlCarousel('.view-team', '#team-section');

	function moveNavigationOwlCarousel(viewClass, sectionid) {
		var portfolio_owl_control = $( viewClass +' .owl-controls');
		$(viewClass + ' .owl-controls').removeClass();
		portfolio_owl_control.addClass('carousel-arrows owl-arrows');
		portfolio_owl_control.find('.owl-prev').append('<i class="fa fa-chevron-left"></i>');
		portfolio_owl_control.find('.owl-next').append('<i class="fa fa-chevron-right"></i>');
		$(sectionid + ' ' + viewClass).append(portfolio_owl_control);
		if ($(sectionid + ' .owl-item').length > 0) {
			var clone_item = $(sectionid + ' .owl-item').first().clone();
			clone_item.html($(sectionid + ' .view-header'));
			$(sectionid + ' .view-header').remove();
			$(sectionid + ' .owl-wrapper-outer .owl-wrapper').prepend(clone_item);
		}
	}	

	function updateWidthFirstItemOwlCarousel(sectionid) {
		if ($(sectionid + ' .owl-item').length > 1) {
			var clone_item = $(sectionid + ' .owl-item').last().clone();			
			clone_item.html($(sectionid + ' .owl-item').html());
			$(sectionid + ' .owl-item').first().remove();			
			$(sectionid + ' .owl-wrapper-outer .owl-wrapper').prepend(clone_item);
		}
	}
	var waitForFinalEvent = (function () {
	  var timers = {};
	  return function (callback, ms, uniqueId) {
	    if (!uniqueId) {
	      uniqueId = "Don't call this twice without a uniqueId";
	    }
	    if (timers[uniqueId]) {
	      clearTimeout (timers[uniqueId]);
	    }
	    timers[uniqueId] = setTimeout(callback, ms);
	  };
	})();
	winDow.bind('resize', function(){
		var selector = $filter.find('a.active').attr('data-filter');

		try {
			//
			waitForFinalEvent(function(){
	      updateWidthFirstItemOwlCarousel('#featured-section');
				updateWidthFirstItemOwlCarousel('#clients-section');
				updateWidthFirstItemOwlCarousel('#team-section');
	      //...
	    }, 500, "some unique string");			

			$container.isotope({ 
				filter	: selector,
				animationOptions: {
					duration: 750,
					easing	: 'linear',
					queue	: false,
				}
			});
			
		} catch(err) {
		}
		return false;
	});	

	/*-------------------------------------------------*/
	/* =  preloader function
	/*-------------------------------------------------*/
	winDow.load( function(){
		var mainDiv = $('#container'),
			preloader = $('.preloader');

			preloader.fadeOut(400, function(){
				mainDiv.delay(400).addClass('active');
			});
	});

	/*-------------------------------------------------*/
	/* =  browser detect
	/*-------------------------------------------------*/
	try {
		$.browserSelector();
		// Adds window smooth scroll on chrome.
		if($("html").hasClass("chrome")) {
			$.smoothScroll();
		}
	} catch(err) {

	}

	/*-------------------------------------------------*/
	/* = video background
	/*-------------------------------------------------*/

	try{
		jQuery(".player").mb_YTPlayer();
	} catch(err) {
	}	
	
	/*-------------------------------------------------*/
	/* =  Animated content
	/*-------------------------------------------------*/

	try {
		/* ================ ANIMATED CONTENT ================ */
        if ($(".animated")[0]) {
            $('.animated').css('opacity', '0');
        }

        $('.triggerAnimation').waypoint(function() {
            var animation = $(this).attr('data-animate');
            $(this).css('opacity', '');
            $(this).addClass("animated " + animation);

        },
                {
                    offset: '75%',
                    triggerOnce: true
                }
        );
	} catch(err) {

	}

	/*-------------------------------------------------*/
	/* =  remove animation in mobile device
	/*-------------------------------------------------*/
	if ( winDow.width() < 992 ) {
		$('div.triggerAnimation').removeClass('animated');
		$('div.triggerAnimation').removeClass('triggerAnimation');
	}	
	
	/* ---------------------------------------------------------------------- */
	/*	Contact Map
	/* ---------------------------------------------------------------------- */
	var contact = {"lat":"-33.880641", "lon":"151.204298"}; //Change a map coordinate here!

	try {
		var mapContainer = $('#map-section');
		var pathToTheme = Drupal.settings.basePath + "sites/all/themes/" + Drupal.settings.ajaxPageState.theme;
    var image = pathToTheme + '/images/marker.png';
		mapContainer.gmap3({
			action: 'addMarker',
			marker:{
				options:{
					icon : new google.maps.MarkerImage(image)
				}
			},
			latLng: [contact.lat, contact.lon],
			map:{
				center: [contact.lat, contact.lon],
				zoom: 15
				},
			},
			{action: 'setOptions', args:[{scrollwheel:false}]}
		);
	} catch(err) {

	}

	/* ---------------------------------------------------------------------- */
	/*	magnific-popup
	/* ---------------------------------------------------------------------- */

	try {
		// Example with multiple objects
		$('.zoom').magnificPopup({
			type: 'image',
			gallery: {
				enabled: true
			}
		});

	} catch(err) {

	}
	
	/*-------------------------------------------------*/
	/* = slider Testimonial
	/*-------------------------------------------------*/

	var slidertestimonial = $('.bxslider');
	try{		
		slidertestimonial.bxSlider({
			mode: 'vertical'
		});
	} catch(err) {
	}

	/* ---------------------------------------------------------------------- */
	/*	Contact Form
	/* ---------------------------------------------------------------------- */

	var submitContact = $('#submit_contact'),
		message = $('#msg');

	submitContact.on('click', function(e){
		e.preventDefault();

		var $this = $(this);
		
		$.ajax({
			type: "POST",
			url: 'contact.php',
			dataType: 'json',
			cache: false,
			data: $('#contact-form').serialize(),
			success: function(data) {

				if(data.info !== 'error'){
					$this.parents('form').find('input[type=text],textarea,select').filter(':visible').val('');
					message.hide().removeClass('success').removeClass('error').addClass('success').html(data.msg).fadeIn('slow').delay(5000).fadeOut('slow');
				} else {
					message.hide().removeClass('success').removeClass('error').addClass('error').html(data.msg).fadeIn('slow').delay(5000).fadeOut('slow');
				}
			}
		});
	});


	/* ---------------------------------------------------------------------- */
	/*	Header animate after scroll
	/* ---------------------------------------------------------------------- */

	(function() {

		var docElem = document.documentElement,
			didScroll = false,
			changeHeaderOn = 40;
			document.querySelector( 'header' );
		function init() {
			window.addEventListener( 'scroll', function() {
				if( !didScroll ) {
					didScroll = true;
					setTimeout( scrollPage, 100 );
				}
			}, false );
		}
		
		function scrollPage() {
			var sy = scrollY();
			if ( sy >= changeHeaderOn ) {
				$( 'header' ).addClass('active');
			}
			else {
				$( 'header' ).removeClass('active');
			}
			didScroll = false;
		}
		
		function scrollY() {
			return window.pageYOffset || docElem.scrollTop;
		}
		
		init();
		
	})();

});

$(window).load(function() {
	callPlayer("video_control", "mute");
	callPlayer("video_control", "stopVideo");
	var playButton = $('.play-button');    
	playButton.live('click', function(e){
		e.preventDefault();
		
		if( !$(this).hasClass('active') ) {
			$(this).addClass('active');
			callPlayer("video_control", "playVideo");
		} else {
			$(this).removeClass('active');
			callPlayer("video_control", "pauseVideo");
		}
	});		

	// vimeo video - enable if you use vimeo

	// jQuery('#video_control').vimeo('mute');
	// 	var playButton = $('.play-button');    
	// 	playButton.live('click', function(e){
	// 		e.preventDefault();
				
	// 		if( !$(this).hasClass('active') ) {
	// 			$(this).addClass('active');
	// 			jQuery('#video_control').vimeo('play');				
	// 		} else {
	// 			$(this).removeClass('active');
	// 			jQuery('#video_control').vimeo('pause');	
	// 		}
	// 	});
	
});


/**
 * @author       Rob W <gwnRob@gmail.com>
 * @website      http://stackoverflow.com/a/7513356/938089
 * @version      20131010
 * @description  Executes function on a framed YouTube video (see website link)
 *               For a full list of possible functions, see:
 *               https://developers.google.com/youtube/js_api_reference
 * @param String frame_id The id of (the div containing) the frame
 * @param String func     Desired function to call, eg. "playVideo"
 *        (Function)      Function to call when the player is ready.
 * @param Array  args     (optional) List of arguments to pass to function func*/
function callPlayer(frame_id, func, args) {
  if (window.jQuery && frame_id instanceof jQuery) frame_id = frame_id.get(0).id;
  var iframe = document.getElementById(frame_id);
  if (iframe && iframe.tagName.toUpperCase() != 'IFRAME') {
      iframe = iframe.getElementsByTagName('iframe')[0];
  }

  // When the player is not ready yet, add the event to a queue
  // Each frame_id is associated with an own queue.
  // Each queue has three possible states:
  //  undefined = uninitialised / array = queue / 0 = ready
  if (!callPlayer.queue) callPlayer.queue = {};
  var queue = callPlayer.queue[frame_id],
      domReady = document.readyState == 'complete';

  if (domReady && !iframe) {
      // DOM is ready and iframe does not exist. Log a message
      window.console && console.log('callPlayer: Frame not found; id=' + frame_id);
      if (queue) clearInterval(queue.poller);
  } else if (func === 'listening') {
      // Sending the "listener" message to the frame, to request status updates
      if (iframe && iframe.contentWindow) {
          func = '{"event":"listening","id":' + JSON.stringify(''+frame_id) + '}';
          iframe.contentWindow.postMessage(func, '*');
      }
  } else if (!domReady ||
             iframe && (!iframe.contentWindow || queue && !queue.ready) ||
             (!queue || !queue.ready) && typeof func === 'function') {
      if (!queue) queue = callPlayer.queue[frame_id] = [];
      queue.push([func, args]);
      if (!('poller' in queue)) {
          // keep polling until the document and frame is ready
          queue.poller = setInterval(function() {
              callPlayer(frame_id, 'listening');
          }, 250);
          // Add a global "message" event listener, to catch status updates:
          messageEvent(1, function runOnceReady(e) {
              if (!iframe) {
                  iframe = document.getElementById(frame_id);
                  if (!iframe) return;
                  if (iframe.tagName.toUpperCase() != 'IFRAME') {
                      iframe = iframe.getElementsByTagName('iframe')[0];
                      if (!iframe) return;
                  }
              }
              if (e.source === iframe.contentWindow) {
                  // Assume that the player is ready if we receive a
                  // message from the iframe
                  clearInterval(queue.poller);
                  queue.ready = true;
                  messageEvent(0, runOnceReady);
                  // .. and release the queue:
                  while (tmp = queue.shift()) {
                      callPlayer(frame_id, tmp[0], tmp[1]);
                  }
              }
          }, false);
      }
  } else if (iframe && iframe.contentWindow) {
      // When a function is supplied, just call it (like "onYouTubePlayerReady")
      if (func.call) return func();
      // Frame exists, send message
      iframe.contentWindow.postMessage(JSON.stringify({
          "event": "command",
          "func": func,
          "args": args || [],
          "id": frame_id
      }), "*");
  }
  /* IE8 does not support addEventListener... */
  function messageEvent(add, listener) {
      var w3 = add ? window.addEventListener : window.removeEventListener;
      w3 ?
          w3('message', listener, !1)
      :
          (add ? window.attachEvent : window.detachEvent)('onmessage', listener);
  }
}