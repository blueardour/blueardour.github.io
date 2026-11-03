/* Academic paper-reading layout: TOC, active section, progress, small UI. */
(function () {
  'use strict';

  function slugify(text) {
    return String(text)
      .trim()
      .toLowerCase()
      .replace(/[\s　]+/g, '-')
      .replace(/[^\w一-鿿-]/g, '')
      .replace(/-+/g, '-')
      .replace(/^-|-$/g, '');
  }

  function ensureHeadingIds(content) {
    var used = Object.create(null);
    content.querySelectorAll('h2, h3').forEach(function (heading) {
      if (!heading.id) heading.id = slugify(heading.textContent) || 'section';
      var base = heading.id;
      var n = 2;
      while (used[base]) {
        heading.id = base + '-' + n;
        n += 1;
      }
      used[heading.id] = true;
    });
  }

  function buildToc(content, navs) {
    var headings = Array.prototype.slice.call(content.querySelectorAll('h2, h3'));
    if (!headings.length) return [];

    var list = document.createElement('ol');
    headings.forEach(function (heading) {
      if (heading.classList.contains('no-toc')) return;
      var li = document.createElement('li');
      li.className = heading.tagName === 'H3' ? 'toc-h3' : 'toc-h2';
      var link = document.createElement('a');
      link.href = '#' + heading.id;
      link.textContent = heading.textContent.replace(/#$/, '').trim();
      li.appendChild(link);
      list.appendChild(li);
    });

    navs.forEach(function (nav) {
      if (!nav) return;
      nav.innerHTML = '';
      nav.appendChild(list.cloneNode(true));
    });

    return headings.filter(function (h) { return !h.classList.contains('no-toc'); });
  }

  function initActiveToc(headings) {
    if (!headings.length) return;
    var links = Array.prototype.slice.call(
      document.querySelectorAll('.paper-toc__nav a, .paper-toc-mobile__nav a')
    );
    if (!links.length) return;

    var byId = Object.create(null);
    links.forEach(function (link) {
      var id = decodeURIComponent(link.getAttribute('href').slice(1));
      (byId[id] = byId[id] || []).push(link);
    });

    var ticking = false;
    function update() {
      ticking = false;
      var threshold = 120;
      var current = headings[0];
      headings.forEach(function (heading) {
        if (heading.getBoundingClientRect().top <= threshold) current = heading;
      });
      links.forEach(function (link) {
        link.classList.remove('is-active');
        link.removeAttribute('aria-current');
      });
      (byId[current.id] || []).forEach(function (link) {
        link.classList.add('is-active');
        link.setAttribute('aria-current', 'location');
      });
    }
    function onScroll() {
      if (!ticking) {
        ticking = true;
        window.requestAnimationFrame(update);
      }
    }
    window.addEventListener('scroll', onScroll, { passive: true });
    window.addEventListener('resize', onScroll);
    update();
  }

  function initProgress() {
    var bar = document.querySelector('.paper-progress span');
    if (!bar) return;
    var ticking = false;
    function update() {
      ticking = false;
      var doc = document.documentElement;
      var max = doc.scrollHeight - window.innerHeight;
      var ratio = max > 0 ? window.scrollY / max : 0;
      bar.style.width = Math.max(0, Math.min(1, ratio)) * 100 + '%';
    }
    function onScroll() {
      if (!ticking) {
        ticking = true;
        window.requestAnimationFrame(update);
      }
    }
    window.addEventListener('scroll', onScroll, { passive: true });
    window.addEventListener('resize', onScroll);
    update();
  }

  function initTableScroll() {
    document.querySelectorAll('.paper-content table').forEach(function (table) {
      if (table.parentElement && table.parentElement.classList.contains('paper-table-scroll')) return;
      var wrap = document.createElement('div');
      wrap.className = 'paper-table-scroll';
      wrap.setAttribute('role', 'region');
      wrap.setAttribute('tabindex', '0');
      wrap.setAttribute('aria-label', 'Scrollable table');
      table.parentNode.insertBefore(wrap, table);
      wrap.appendChild(table);
    });
  }

  function initLanguageSwitch() {
    document.querySelectorAll('[data-lang-switch]').forEach(function (link) {
      link.addEventListener('click', function () {
        if (!window.location.hash) return;
        var href = link.getAttribute('href') || '';
        if (href.indexOf('#') === -1) link.setAttribute('href', href + window.location.hash);
      });
    });
  }

  function initCopyButtons() {
    document.querySelectorAll('.paper-copy').forEach(function (button) {
      button.addEventListener('click', function () {
        var target = document.getElementById(button.getAttribute('data-copy-target'));
        if (!target) return;
        var text = target.value || target.textContent || '';
        var done = function () {
          var old = button.textContent;
          button.textContent = 'Copied';
          window.setTimeout(function () { button.textContent = old; }, 1600);
        };
        if (navigator.clipboard && navigator.clipboard.writeText) {
          navigator.clipboard.writeText(text).then(done).catch(function () {});
        } else {
          target.select();
          try { document.execCommand('copy'); done(); } catch (e) {}
        }
      });
    });
  }

  function initMobileTocClose() {
    var details = document.querySelector('.paper-toc-mobile');
    if (!details) return;
    details.querySelectorAll('a').forEach(function (link) {
      link.addEventListener('click', function () { details.removeAttribute('open'); });
    });
  }

  function initImages() {
    document.querySelectorAll('.paper-content img').forEach(function (img) {
      if (!img.hasAttribute('decoding')) img.setAttribute('decoding', 'async');
    });
  }

  function init() {
    var content = document.querySelector('.paper-content');
    if (!content) return;
    ensureHeadingIds(content);
    var headings = buildToc(content, [
      document.querySelector('.paper-toc__nav'),
      document.querySelector('.paper-toc-mobile__nav')
    ]);
    initActiveToc(headings);
    initProgress();
    initTableScroll();
    initLanguageSwitch();
    initCopyButtons();
    initMobileTocClose();
    initImages();
  }

  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', init);
  } else {
    init();
  }
}());
