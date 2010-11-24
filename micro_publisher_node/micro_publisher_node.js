// $Id: micro.js, v 1.0 2010/12/01 04:20:00 blup Exp $

(function ($) {

Drupal.behaviors.micro_publisher_node = {
  attach: function (context) {
    $('#micro-publishers').tabs();
  }
};

})(jQuery);
