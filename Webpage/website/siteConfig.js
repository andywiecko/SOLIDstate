/**
 * Copyright (c) 2017-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// See https://docusaurus.io/docs/site-config for all the possible
// site configuration options.

// List of projects/orgs using your project for the users page.
const users = [
  {
    title: 'Andrzej Więckowski',
    caption: 'Andrzej Więckowski',
    image: '/SOLIDstate/img/avatar.jpeg',
    infoLink: 'https://andywiecko.github.io/',
    pinned: true,
  },
];

const siteConfig = {
  title: 'SOLIDstate', // Title for your website.
  tagline: 'A C++ library for solid state physics (Work In Progress)',
  url: 'https://andywiecko.github.io', // Your website URL
  baseUrl: '/SOLIDstate/', // Base URL for your project */
  // For github.io type URLs, you would set the url and baseUrl like:
  //   url: 'https://facebook.github.io',
  //   baseUrl: '/test-site/',

  // Used for publishing and more
  projectName: 'SOLIDstate',
  organizationName: 'andywiecko',
  // For top-level user or org sites, the organization is still the same.
  // e.g., for the https://JoelMarcey.github.io site, it would be set like...
  //   organizationName: 'JoelMarcey'

  // For no header links in the top nav bar -> headerLinks: [],
  headerLinks: [
    {doc: 'getting-started', label: 'Documentation'},
    {href: '/SOLIDstate/api/index.html', label: 'API'},
    {doc: 'examples/example1', label: 'Example codes'},
    {page: 'about', label: 'About'},
    {blog: true, label: 'Blog'},
  ],

  // If you have users set above, you add it here:
  users,

  /* path to images for header/footer */
  headerIcon: 'img/logoWideWhite.png',
  footerIcon: 'img/logoWhite.png',
  favicon: 'img/favicon.png',

  disableHeaderTitle: true,

  /* Colors for website */
  colors: {
    primaryColor: '#005599',
    secondaryColor: '#222222',
  },

  /* Custom fonts for website */
  /*
  fonts: {
    myFont: [
      "Times New Roman",
      "Serif"
    ],
    myOtherFont: [
      "-apple-system",
      "system-ui"
    ]
  },
  */
 
  stylesheets: [
  'https://fonts.googleapis.com/css?family=Source+Sans+Pro:400,400i,700',
  ],


  // This copyright info is used in /core/Footer.js and blog RSS/Atom feeds.
  copyright: `Copyright © ${new Date().getFullYear()} Andrzej Więckowski`,

  highlight: {
    // Highlight.js theme to use for syntax highlighting in code blocks.
    theme: 'default',
  },

  // Add custom scripts here that would be placed in <script> tags.
  scripts: ['https://buttons.github.io/buttons.js','https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.4/MathJax.js?config=TeX-MML-AM_CHTML'],
  
  // On page navigation for the current documentation page.
  onPageNav: 'separate',
  // No .html extensions for paths.
  cleanUrl: true,

  // Open Graph and Twitter card images.
  ogImage: 'img/undraw_online.svg',
  twitterImage: 'img/undraw_tweetstorm.svg',

  // For sites with a sizable amount of content, set collapsible to true.
  // Expand/collapse the links and subcategories under categories.
  docsSideNavCollapsible: true,

  // Show documentation's last contributor's name.
  enableUpdateBy: true,

  // Show documentation's last update time.
  enableUpdateTime: true,

  // You may provide arbitrary config keys to be used as needed by your
  // template. For example, if you need your repo's URL...
  repoUrl: 'https://github.com/andywiecko/SOLIDstate',


  scrollToTop: true,

};

module.exports = siteConfig;
