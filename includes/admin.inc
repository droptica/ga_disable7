<?php

/**
 * Page callback: Admin form.
 */
function ga_disable_admin_settings_form($form, &$form_state) {
  $form['ga_disable_id'] = [
    '#type' => 'textfield',
    '#title' => t('Google Analytics ID'),
    '#description' => t('Enter the ID used by Google Analytics, like UA-1234567-8.'),
    '#default_value' => variable_get('ga_disable_id', ''),
  ];
  $form['ga_disable_dev_environments'] = array(
    '#type' => 'textarea',
    '#title' => t('Dev environments'),
    '#default_value' => variable_get('ga_disable_dev_environments', ''),
    '#description' => t('Enter the list of environments for which GA will be always disabled (in this case the cookie will be bypassed). The environment is taken from `ENV` system variable. Please put one environment in the row.'),
    '#rows' => 5,
  );
  $form['ga_disable_cookie_domains'] = array(
    '#type' => 'textarea',
    '#title' => t('Cookie domains'),
    '#default_value' => variable_get('ga_disable_cookie_domains', ''),
    '#description' => t('Enter one domain in a row.'),
    '#rows' => 5,
  );
  $form['help'] = [
    '#type' => 'item',
    '#title' => t('Setting the cookie'),
    '#markup' => t('Click <a href="/ga_disable/set_cookie">here</a> to set the cookie for the session. Click <a href="/ga_disable/remove_cookie">here</a> to remove it.'),
  ];

  return system_settings_form($form);
}
