<?php
/**
 * @file
 * Creates the condition check for context plugin.
 */

/**
 * Expose the specified theme as a contet condition.
 */
class mr_context_admintheme extends context_condition {
  function condition_values() {
    $values = array(1 => 'Trigger this context when viewing pages in the admin theme.');
    return $values;
  }
  function execute() {
    global $theme_key;
    if ($theme_key == variable_get('admin_theme')) {
      foreach ($this->get_contexts() as $context) {
        $this->condition_met($context);
      }
    }
  }
}