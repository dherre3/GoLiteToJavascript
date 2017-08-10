import { Component, ViewChild, Input, OnInit } from '@angular/core';
declare var ace: any;
@Component({
  selector: 'app-left-panel',
  templateUrl: './left-panel.component.html',
  styleUrls: ['./left-panel.component.css']
})
export class LeftPanelComponent implements  OnInit {

  _height: string;
  @Input('height')
  set height(value: number) {
    if (value) {
      this._height = value + 'px';
    }
  }
  public source = `package main;
  var a:int;
func main() {
  print("Hello World")'
}`;
  @ViewChild('highlight') highlight;
  @ViewChild('editor') editor;
  ngOnInit() {
    this.editor.setTheme('xcode');
    this.editor.getEditor().$blockScrolling = Infinity;
  }
}
