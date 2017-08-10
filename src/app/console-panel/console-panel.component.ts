import { Component, OnInit, AfterViewInit, Input, ViewChild, OnDestroy} from '@angular/core';
import {CompilerRequestService} from '../compiler-request.service';
import { Subscription } from 'rxjs/Subscription';

declare const ace: any;

@Component({
  selector: 'app-console-panel',
  templateUrl: './console-panel.component.html',
  styleUrls: ['./console-panel.component.css']
})
export class ConsolePanelComponent implements OnInit, AfterViewInit, OnDestroy {
  @ViewChild('consoleEditor') consoleEditor;
  subscription: Subscription;
  errorCode: string;
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
    this.subscription = compilerRequestServer.errorAnnounced$.subscribe( error => {this.errorCode = error; });
  }


  ngOnInit() {
    this.consoleEditor.setTheme('xcode');
  }

  ngAfterViewInit() {
    this.consoleEditor.getEditor().setReadOnly(true);
  }
  ngOnDestroy() {
    this.subscription.unsubscribe();
  }
}
