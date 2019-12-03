/**
 * Copyright (c) 2017-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

const React = require('react');

const CompLibrary = require('../../core/CompLibrary.js');

const MarkdownBlock = CompLibrary.MarkdownBlock; /* Used to read markdown */
const Container = CompLibrary.Container;
const GridBlock = CompLibrary.GridBlock;

class HomeSplash extends React.Component {
  render() {
    const { siteConfig, language = '' } = this.props;
    const { baseUrl, docsUrl } = siteConfig;
    const docsPart = `${docsUrl ? `${docsUrl}/` : ''}`;
    const langPart = `${language ? `${language}/` : ''}`;
    const docUrl = doc => `${baseUrl}${docsPart}${langPart}${doc}`;

    const SplashContainer = props => (




      <div className="homeContainer">
        <div className="homeSplashFade">
          <div className="wrapper homeWrapper">{props.children}</div>
        </div>
      </div>
    );

    const Logo = props => (
      <div className="projectLogo">
        <img src={props.img_src} alt="Project Logo" />
      </div>
    );

    const TitleLogo = props => (
      <div className="projectTitleLogo">
        <img src={props.img_src} alt="Project Title Logo" width="600" />
      </div>
    );

    const ProjectTitle = () => (
      <h2 className="projectTitle">
        {/*</h2>siteConfig.title*/}
        <small>{siteConfig.tagline}</small>
      </h2>
    );

    const PromoSection = props => (
      <div className="section promoSection">
        <div className="promoRow">
          <div className="pluginRowBlock">{props.children}</div>
        </div>
      </div>
    );

    const Button = props => (
      <div className="pluginWrapper buttonWrapper">
        <a className="button" href={props.href} target={props.target}>
          {props.children}
        </a>
      </div>
    );

    return (


      <SplashContainer>
        <div >
          <TitleLogo img_src={`${baseUrl}img/logo-wide.png`} />
        </div>
        <div className="inner">

          <ProjectTitle siteConfig={siteConfig} />
          <PromoSection>
            <Button href="#try">Try It Out</Button>
            <Button href="https://github.com/andywiecko/SOLIDstate">GitHub</Button>
            <Button href={docUrl('getting-started.html')}>Example Link</Button>
            <Button href={docUrl('doc2.html')}>Download .zip v1.0.0</Button>
          </PromoSection>
        </div>

      </SplashContainer>
    );
  }
}

class Index extends React.Component {
  render() {
    const { config: siteConfig, language = '' } = this.props;
    const { baseUrl } = siteConfig;

    const Block = props => (
      <Container
        padding={['bottom', 'top']}
        id={props.id}
        background={props.background}>
        <GridBlock
          align="center"
          contents={props.children}
          layout={props.layout}
        />
      </Container>
    );

    const FeatureCallout = () => (
      <div
        className="productShowcaseSection paddingBottom"
        style={{ textAlign: 'center' }}>
        <h2>Feature Callout</h2>
        <MarkdownBlock>These are features of this project</MarkdownBlock>
      </div>
    );

    const TryOut = () => (
      <Block id="try">
        {[
          {
            content:
              'To make your landing page more attractive, use illustrations! Check out ' +
              '[**unDraw**](https://undraw.co/) which provides you with customizable illustrations which are free to use. ' +
              'The illustrations you see on this page are from unDraw.',
            image: `${baseUrl}img/undraw_code_review.svg`,
            imageAlign: 'left',
            title: 'Wonderful SVG Illustrations',
          },
        ]}
      </Block>
    );

    const Description = () => (
      <Block background="dark">
        {[
          {
            content:
              'SOLIDstate is a dynamic shared C++ library designed for small quantum system studies with many-body interactions.',
            image: `${baseUrl}img/undraw_science_fqhl.svg`,
            imageAlign: 'right',
            title: 'Description',
          },
        ]}
      </Block>
    );

    const LearnHow = () => (
      <Block background="light">
        {[
          {
            content:
              'Each new Docusaurus project has **randomly-generated** theme colors.',
            image: `${baseUrl}img/undraw_youtube_tutorial.svg`,
            imageAlign: 'right',
            title: 'Randomly Generated Theme Colors',
          },
        ]}
      </Block>
    );

    const Features = () => (
      <Block layout="fourColumn">
        {[
          {
            content: 'SOLIDstate depends on powerfull C++ library: [Armadillo](http://arma.sourceforge.net/)',
            image: `${baseUrl}img/armadillo_logo.png`,
            imageAlign: 'top',
            title: '[Armadillo](http://arma.sourceforge.net/)',
          },
          {
            content: 'Easly switch between sparse and dense matrix types for storing Hamiltonian: `arma::Mat`, `arma::SpMat`',
            image: `${baseUrl}img/undraw_selection_92i4.svg`,
            imageAlign: 'top',
            title: 'Switch between matrix types',
          },
          {
            content: 'Easly switch between different statistical ensembles: `Canonical`, `Grand canonical`, `Parity Conserved Grand Canonical` and more',
            image: `${baseUrl}img/undraw_options_2fvi.svg`,
            imageAlign: 'top',
            title: 'Switch between ensembles',
          },
          {
            content: 'Easly switch between different data types: `double`, `complex<double>`',
            image: `${baseUrl}img/undraw_Choose_bwbs.svg`,
            imageAlign: 'top',
            title: 'Switch between data types',
          },
        ]}
      </Block>
    );

    const Showcase = () => {
      if ((siteConfig.users || []).length === 0) {
        return null;
      }

      const showcase = siteConfig.users
        .filter(user => user.pinned)
        .map(user => (
          <a href={user.infoLink} key={user.infoLink}>
            <img src={user.image} alt={user.caption} title={user.caption} />
          </a>
        ));

      const pageUrl = page => baseUrl + (language ? `${language}/` : '') + page;

      return (
        <div className="productShowcaseSection paddingBottom">
          <h2>Who is Using This?</h2>
          <p>This project is used by all these people</p>
          <div className="logos">{showcase}</div>
          <div className="more-users">
            <a className="button" href={pageUrl('users.html')}>
              More {siteConfig.title} Users
            </a>
          </div>
        </div>
      );
    };

    return (
      <div>
        <HomeSplash siteConfig={siteConfig} language={language} />
        <div className="mainContainer">
          <Features />
          <FeatureCallout />
          <Description />
          <Showcase />
        </div>
      </div>
      //<TryOut />
      //<LearnHow />
    );
  }
}

module.exports = Index;
