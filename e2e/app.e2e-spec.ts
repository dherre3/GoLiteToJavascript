import { GoJsWebsitePage } from './app.po';

describe('go-js-website App', () => {
  let page: GoJsWebsitePage;

  beforeEach(() => {
    page = new GoJsWebsitePage();
  });

  it('should display message saying app works', () => {
    page.navigateTo();
    expect(page.getParagraphText()).toEqual('app works!');
  });
});
