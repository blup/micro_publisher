// $Id: micro_publisher.js, v 1.0 2010/12/01 04:20:00 blup Exp $

(function($){$(document).ready(function(){
  $('.micro-publisher').tabs();
  $( ".tabs-bottom .ui-tabs-nav, .tabs-bottom .ui-tabs-nav > *" )
      .removeClass( "ui-corner-all ui-corner-top" )
      .addClass( "ui-corner-bottom" );
  });
})(jQuery);
