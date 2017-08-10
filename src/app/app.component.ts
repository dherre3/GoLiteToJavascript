import { Component, ViewChild } from '@angular/core';
import { LeftPanelComponent } from './left-panel/left-panel.component';
import { CompilerRequestService } from './compiler-request.service';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css'],
  providers: [CompilerRequestService]
})
export class AppComponent {

  public heightConsole: number;
  public heightPanels: number;
  @ViewChild(LeftPanelComponent)
  private leftPanelComponent: LeftPanelComponent;

  constructor(private compilerService: CompilerRequestService) {

  }
  compile() {
    this.compilerService.sendRequest( 'GoToJS', this.leftPanelComponent.source);
  }

  onHChange(e) {
    this.heightConsole = e.secondary;
    this.heightPanels = e.primary;
  }
}
