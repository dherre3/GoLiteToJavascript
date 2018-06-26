import { Component, ViewChild, Input, OnInit } from '@angular/core';
import 'brace';
import 'brace/index';
import 'brace/theme/xcode';
import 'brace/mode/golang';


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
  public source = `package main
//Variable Declarations
var a int 
var (
	ToBe   bool       = false
	c float64 = 123.12312
	d []int
	
)
//Type declarations
type intAlias int
func main() {
  //Printing
  print("Hello World");
  //Appending slice
  d = append(d,3);
}`;
  @ViewChild('editor') editor;
  ngOnInit() {
    this.editor.getEditor().$blockScrolling = Infinity;
  }
}
