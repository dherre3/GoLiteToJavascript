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
  //String types, short decl
  a, v, h := "dadas\t", \`
        \t\t\`, '\t';
  //Struc types
  var t struct {
      b int
      nb intAlias
  }
  //For Loops
  for i := 0; i < 10; i-- {
	print(a)
  }
  //Switch Statements
  
  switch tag:=3; tag {
    case 0, 1, 2, 3: 
    case 4, 5, 6, 7: 
    default:
  }

}`;
  @ViewChild('editor') editor;
  ngOnInit() {
    this.editor.setTheme('xcode');
    this.editor.getEditor().$blockScrolling = Infinity;
  }
}
