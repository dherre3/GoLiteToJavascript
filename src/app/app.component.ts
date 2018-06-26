import { Component, ViewChild, ChangeDetectorRef } from '@angular/core';
import { LeftPanelComponent } from './left-panel/left-panel.component';
import { CompilerRequestService } from './compiler-request.service';
import 'brace';
import 'brace/index';
import 'brace/theme/xcode';
import 'brace/mode/text';
import 'brace/mode/golang';
import 'brace/mode/javascript';
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

  constructor(private compilerService: CompilerRequestService, private cdr: ChangeDetectorRef) {

  }
  compile() {
    this.compilerService.sendRequest( 'GoToJS', this.leftPanelComponent.source);
  }

  onHChange(e) {
    this.heightConsole = e.secondary;
    this.heightPanels = e.primary;
    this.cdr.detectChanges();

  }
}
