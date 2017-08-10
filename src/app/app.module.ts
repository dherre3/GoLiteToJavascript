import { BrowserModule } from '@angular/platform-browser';
import {BrowserAnimationsModule} from '@angular/platform-browser/animations';
import {  MdToolbarModule, MdIconModule, MdButtonModule,
          MdGridListModule, MdDialogModule, MdCardModule, MdTabsModule } from '@angular/material';

import { NgModule } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { HttpClientModule } from '@angular/common/http';
import { AppComponent } from './app.component';
import { ScriptComponent } from './script/script.component';
import { ToolbarComponent } from './toolbar/toolbar.component';
import { RightPanelComponent } from './right-panel/right-panel.component';
import { LeftPanelComponent } from './left-panel/left-panel.component';
import { ConsolePanelComponent } from './console-panel/console-panel.component';
import { AboutComponent } from './toolbar/about/about.component';
import { AceEditorModule } from 'ng2-ace-editor';
import { SplitPaneModule } from 'ng2-split-pane/lib/ng2-split-pane';

@NgModule({
  declarations: [
    AppComponent,
    ScriptComponent,
    ToolbarComponent,
    RightPanelComponent,
    LeftPanelComponent,
    ConsolePanelComponent,
    AboutComponent,
  ],
  imports: [
    BrowserModule,
    FormsModule,
    HttpClientModule,
    BrowserAnimationsModule,
    MdToolbarModule,
    MdIconModule,
    MdButtonModule,
    MdGridListModule,
    MdDialogModule,
    MdCardModule,
    AceEditorModule,
    MdTabsModule,
    SplitPaneModule
  ],
  providers: [],
  bootstrap: [AppComponent],
  entryComponents: [AboutComponent]
})
export class AppModule { }
