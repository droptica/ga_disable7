<?php

/**
 * Page callback: Set cookie.
 */
function ga_disable_set_cookie() {
  setcookie("analytics_disable", TRUE, 0, '/');
  drupal_set_message(t('The GA opt-out cookie has been set.'), 'status');
  drupal_goto('<front>');
}

/**
 * Page callback: Remove cookie.
 */
function ga_disable_remove_cookie() {
  setcookie("analytics_disable", FALSE, time() - 3600, '/');
  drupal_set_message(t('The GA opt-out cookie has been removed.'), 'status');
  drupal_goto('<front>');
}