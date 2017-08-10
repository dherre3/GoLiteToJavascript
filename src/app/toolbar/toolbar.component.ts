import { Component, OnInit, EventEmitter, Output } from '@angular/core';
import { MdDialog } from '@angular/material';
import { AboutComponent } from './about/about.component';
@Component({
  selector: 'app-toolbar',
  templateUrl: './toolbar.component.html',
  styleUrls: ['./toolbar.component.css']
})
export class ToolbarComponent implements OnInit {
  @Output() onCompile: EventEmitter<null>;
  constructor(public aboutDialog: MdDialog) {
    this.onCompile = new EventEmitter<null>();
  }

  ngOnInit() {
  }
  compiler() {
    this.onCompile.emit(null);
  }
  openAbout() {
    console.log(AboutComponent);
    this.aboutDialog.open(AboutComponent);
  }

}
