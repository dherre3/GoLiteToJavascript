package main
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
  a, v, h := "dadas	", `
    `, '	';
  //Struct types
  var t struct {
      b int
      nb intAlias
  }
  //Appending slice
  d = append(d,3);
}