// Custom scripts file
// to load, uncomment the call to this file in sugufi.info

(function ($) {
    'use strict';
    Drupal.behaviors.ResponsiveCarousel ={
        attach:function(){
            var $postcarousel = $('.jcarousel');
            if( $postcarousel.length) {
                $postcarousel.jcarousel({
                    animation : 500,
                    setupCallback: function(carousel) {
                        carousel.reload();
                    },
                    reloadCallback: function(carousel) {

                        var width = $(window).width();
                        if (width < 600) {
                            width = width / 2;
                            $(this).jcarousel('items').css('width', width + 'px');
                        }

                    }
                });
            }
        }
    }


  // Generic function that runs on window resize.
  function resizeStuff() {
  }

  // Runs function once on window resize.
  var TO = false;
  $(window).resize(function () {
    if (TO !== false) {
      clearTimeout(TO);
    }

    // 200 is time in miliseconds.
    TO = setTimeout(resizeStuff, 200);
  }).resize();

})(jQuery);
