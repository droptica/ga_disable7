<?php

/**
 * Page callback: Set cookie.
 */
function ga_disable_set_cookie() {
  setcookie("analytics_disable", TRUE, 0, '/');
  $cookie_domains = array_map('trim', explode("\n", variable_get('ga_disable_cookie_domains')));
  foreach (array_filter($cookie_domains) as $domain) {
    setcookie("analytics_disable", TRUE, 0, '/', $domain);
  }
  drupal_goto('<front>');
}

/**
 * Page callback: Remove cookie.
 */
function ga_disable_remove_cookie() {
  setcookie("analytics_disable", FALSE, time() - 3600, '/');
  $cookie_domains = array_map('trim', explode("\n", variable_get('ga_disable_cookie_domains')));
  foreach (array_filter($cookie_domains) as $domain) {
    setcookie("analytics_disable", FALSE, time() - 3600, '/', $domain);
  }
  drupal_goto('<front>');
}
