import {Component, OnInit, Input, OnDestroy, ViewChild} from '@angular/core';
import { CompilerRequestService } from '../compiler-request.service';
import { Subscription } from 'rxjs/Subscription';
@Component({
  selector: 'app-right-panel',
  templateUrl: './right-panel.component.html',
  styleUrls: ['./right-panel.component.css']
})
export class RightPanelComponent implements OnInit, OnDestroy {
  @ViewChild('editorTarget') editorTarget;
  @ViewChild('editorPrettyTyped') editorPrettyTyped;
  activeTab: number;
  subscription: Subscription;
  private tabs: Array<{editor: any, editorContent: string}>;

  _height: string;
  @Input('height')
  set height(value: number) {
    if (value) {
      this._height = (value - 53) + 'px';
    }
  }
  constructor(private compilerService: CompilerRequestService) {
    this.subscription = compilerService.programAnnounced$.subscribe(
      (code) => {
        this.tabs[0].editorContent = code.target;
        this.tabs[1].editorContent = code.pptype;
      }
    );
  }

  ngOnInit() {
    this.editorTarget.setTheme('xcode');
    this.editorPrettyTyped.setTheme('xcode');
    this.tabs = [ {editor: this.editorTarget, editorContent: ''},
                  {editor: this.editorPrettyTyped, editorContent: ''}];
  }

  onTabChange(e) {
    this.activeTab = e.index;
    const currentEditor = this.tabs[e.index].editor.getEditor();
    currentEditor.setValue(this.tabs[this.activeTab].editorContent);
    currentEditor.clearSelection();
    currentEditor.$blockScrolling = Infinity;
  }

  ngOnDestroy() {
    this.subscription.unsubscribe();
  }

}

