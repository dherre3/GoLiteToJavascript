import { BrowserModule } from '@angular/platform-browser';
import {  MdToolbarModule, MdIconModule, MdButtonModule,
          MdGridListModule, MdDialogModule, MdCardModule, MdTabsModule, MdProgressBarModule } from '@angular/material';
import {BrowserAnimationsModule} from '@angular/platform-browser/animations';

import { NgModule } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { HttpClientModule } from '@angular/common/http';
import { AppComponent } from './app.component';
import { ToolbarComponent } from './toolbar/toolbar.component';
import { RightPanelComponent } from './right-panel/right-panel.component';
import { LeftPanelComponent } from './left-panel/left-panel.component';
import { ConsolePanelComponent } from './console-panel/console-panel.component';
import { AboutComponent } from './toolbar/about/about.component';
import { AceEditorModule } from 'ng2-ace-editor';
import { SplitPaneModule } from 'ng2-split-pane/lib/ng2-split-pane';
import { BottomToolbarComponent } from './bottom-toolbar/bottom-toolbar.component';

@NgModule({
  declarations: [
    AppComponent,
    ToolbarComponent,
    RightPanelComponent,
    LeftPanelComponent,
    ConsolePanelComponent,
    AboutComponent,
    BottomToolbarComponent,
  ],
  imports: [
    BrowserModule,
    FormsModule,
    HttpClientModule,
    MdToolbarModule,
    MdIconModule,
    MdButtonModule,
    MdGridListModule,
    MdDialogModule,
    MdCardModule,
    AceEditorModule,
    MdTabsModule,
    SplitPaneModule,
    MdProgressBarModule,
    BrowserAnimationsModule
  ],
  providers: [],
  bootstrap: [AppComponent],
  entryComponents: [AboutComponent]
})
export class AppModule { }
