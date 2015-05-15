var $ = jQuery.noConflict();

$(document).ready(function($) {
	"use strict";	

	try{	
		if ($(".animated")[0]) {
			$('.animated').css('opacity', '0');
		}

		$('.triggerAnimation').waypoint(function() {			
			var animation = $(this).attr('data-animate');
			$(this).css('opacity', '');
			$(this).addClass(animation);
		},
		{
			offset: '80%',
			triggerOnce: true
		}
		);		
	} catch(err) {
	}

	// JavaScript Document

    
  var $allVideos = jQuery("iframe[src^='http://player.vimeo.com'], iframe[src^='//player.vimeo.com'], iframe[src^='//www.youtube.com'], iframe[src^='http://www.youtube.com'],object, embed"),
  $fluidEl = jQuery(".st-block .background");
	  	
	$allVideos.each(function() {		
	  $(this)
	    // jQuery .data does not work on object/embed elements
	    .attr('oldWidth', this.width)
	    .attr('data-aspectRatio', this.height / this.width)
	    .removeAttr('height')
	    .removeAttr('width');	      
	});
	
	jQuery(window).resize(function() {	
	
	  var newWidth = $fluidEl.width();
	  var newHeight = $fluidEl.height();
	  $allVideos.each(function() {
	  
	    var $el = jQuery(this);
	    if (newWidth >= $el.attr('oldWidth')) {
	    	$el
	        .width(newWidth)
	        .height(newWidth * $el.attr('data-aspectRatio'));
	    }
	    else {
	    	$el
	        .height(newHeight)
	        .width(newHeight / $el.attr('data-aspectRatio'));
	    }
	  	$el.attr('oldWidth', $el.width());
	  });
	
	}).resize();	

	var $vimeo_videos = jQuery("iframe[src^='http://player.vimeo.com'], iframe[src^='//player.vimeo.com']");
	var $youtube_videos = jQuery("iframe[src^='//www.youtube.com'], iframe[src^='http://www.youtube.com']");

	$vimeo_videos.each(function() {
		jQuery(this).vimeo('setVolume', 0);
	});	

 	var tag = document.createElement('script');

	tag.src = "https://www.youtube.com/iframe_api";
	var firstScriptTag = document.getElementsByTagName('script')[0];
	firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);

	var player;
	var yt_int,iy=0,yt_players={};
	try {
		$.getScript("//www.youtube.com/player_api", function() {
	    yt_int = setInterval(function(){	    	
        if(typeof YT === "object"){
            $youtube_videos.each(function() {
            	try {
            		if (this.id != 'video_control') {
            			$(this).attr('id', 'youtube_' + iy);	
            		}
            		
		            yt_players[this.id] = new YT.Player(this.id, {
		            	events: {
						        'onReady': onPlayerReady,
						        'onStateChange': onPlayerStateChange
						      }
		            });  
		                      
		            iy++;
				    	}
				    	catch(err) {
				    		
				    	}		        	  
		        });   				    
		    };	            	            
        clearInterval(yt_int);      
  		},500);
		});	
	}
	catch(err) {		
	}	     
	

	/*-------------------------------------------------*/
	/* =  smooth scroll in chrome
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
	/* =  parallax
	/*-------------------------------------------------*/
	
	try{
		$('.st-block-parallax').appear(function() {	
			var block = $(this);
			$.stellar({
				horizontalScrolling: false,
			    verticalOffset: 0,
			    horizontalOffset: 0		
			});
		});
	} catch(err) {
	}

});

function onPlayerReady(event) {  	    
  event.target.mute();      
}

function onPlayerStateChange(event) {
	event.target.mute();
}