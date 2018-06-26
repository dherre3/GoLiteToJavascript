import { Component, OnInit, Input, ViewChild, OnDestroy, } from '@angular/core';
import {CompilerRequestService} from '../compiler-request.service';
import { Subscription } from 'rxjs/Subscription';
import 'brace';
import 'brace/index';
import 'brace/theme/xcode';
import 'brace/mode/text';

@Component({
  selector: 'app-console-panel',
  templateUrl: './console-panel.component.html',
  styleUrls: ['./console-panel.component.css']
})
export class ConsolePanelComponent implements  OnInit, OnDestroy {
  @ViewChild('consoleEditor') consoleEditor;
  subscriptionError: Subscription;
  subscriptionRun: Subscription;
  subscriptionClear: Subscription;
  code: string;
  codeColor: string;
  public _height: string;

  @Input('height')
  set height(value: number) {
    if (value) {
      this._height = value + 'px';
    }else {
      this._height = '100px';
    }
  }



  constructor(private compilerRequestServer: CompilerRequestService) {

    this.subscriptionClear = compilerRequestServer.clearAnnounced$.subscribe(res => this.code = '');
    this.subscriptionError = compilerRequestServer.errorAnnounced$.subscribe( error => {
      this.code = error;
      this.codeColor = 'red';
    });
    this.subscriptionRun = compilerRequestServer.runAnnounced$.subscribe(res => {
      this.code = res;
      this.codeColor = 'green';
    });
  }


  ngOnInit() {
    this.consoleEditor.getEditor().setReadOnly(true);
    this.consoleEditor.getEditor().$blockScrolling = Infinity;
  }
  ngOnDestroy() {
    this.subscriptionError.unsubscribe();
    this.subscriptionRun.unsubscribe();
    this.subscriptionClear.unsubscribe();
  }
}
