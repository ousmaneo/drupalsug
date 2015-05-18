<?php
/**
 * @file
 * Theme implementation to display a single Drupal page.
 */
?>
<?php if ($page['utility']): ?>
  <?php print render($page['utility']); ?>
<?php endif; ?>

<?php if ($page['navigation']): ?>
  <?php print render($page['navigation']); ?>
<?php endif; ?>
<header class="header" role="banner">
  <?php if ($page['header']): ?>
    <?php print render($page['header']); ?>
  <?php endif; ?>
</header>


<?php if ($page['preface']): ?>
  <?php print render($page['preface']); ?>
<?php endif; ?>

<?php if ($page['content']): ?>
  <main id="main" class="main" role="main" tabindex="-1">
    <?php print render($page['content']); ?>
  </main>
<?php endif; ?>

<?php if ($page['sidebar_second']): ?>
  <aside id="sidebar_second" class="sidebar_second">
    <?php print render($page['sidebar_second']); ?>
  </aside>
<?php endif; ?>

<?php if ($page['postscript']): ?>
  <?php print render($page['postscript']); ?>
<?php endif; ?>

<?php if ($page['footer']): ?>
  <footer class="footer" role="contentinfo">
    <?php print render($page['footer']); ?>
      <div class="copyright">
          <span class="copyright">Copyright <?php echo date('now'); ?>. All rights reserved. Coders4africa</span>
      </div>
  </footer>
<?php endif; ?>
