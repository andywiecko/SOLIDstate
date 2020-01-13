/**
 * Copyright (c) 2017-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

const React = require('react');

const CompLibrary = require('../../core/CompLibrary.js');

const Container = CompLibrary.Container;
const GridBlock = CompLibrary.GridBlock;
const MarkdownBlock = CompLibrary.MarkdownBlock;

function About(props) {
  const {config: siteConfig, language = ''} = props;
  const {baseUrl, docsUrl} = siteConfig;
  const docsPart = `${docsUrl ? `${docsUrl}/` : ''}`;
  const langPart = `${language ? `${language}/` : ''}`;
  const docUrl = doc => `${baseUrl}${docsPart}${langPart}${doc}`;

  const supportLinks = [
    {
      content: `Learn more using the [documentation on this site](${docUrl(
        'getting-started.html',
      )}) or browse the [API](${docUrl(
        '../api/index.html',
      )}).`,
      title: '**Browse Docs**',
    },
    {
      content: 'Ask questions about the documentation, project or join the project and make pull requests.',
      title: '**Join the project**',
    },
    {
      content: "Find out what's new with this project via [Blog](blog) or [GitHub](https://github.com/andywiecko/SOLIDstate).",
      title: '**Stay up to date**',
    },
  ];

  return (
    <div className="docMainWrapper wrapper">
      <Container className="mainContainer documentContainer postContainer">
        <div className="post">
        <header className="postHeader">
          <h1>About</h1>
          </header>
          <MarkdownBlock>
        SOLIDstate is a C++ library, whose main purpose is to study 
        (relatively small systems up to \\( L\sim30 \\) strongly correlated systems).
        SOLIDstate depends on the powerful C++ template library [Armadillo](http://arma.sourceforge.net/).
        The main feature is that user can easily specify the
        type of the solving predefined Hamiltonians (sparse/dense),
        type of the data (double/complex),
        type of the considering statistical ensemble, and more...
        </MarkdownBlock>
        
        <h2>Help</h2> 
        <MarkdownBlock>
        Need help? This project is maintained by Andrzej Więckowski [andrzej.wieckowski (at) pwr.edu.pl].
        </MarkdownBlock>

          
          <GridBlock contents={supportLinks} layout="threeColumn" />
        </div>
      </Container>
    </div>
  );
}

module.exports = About;
