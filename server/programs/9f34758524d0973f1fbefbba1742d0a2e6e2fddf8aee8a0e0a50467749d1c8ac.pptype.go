package main
var a int
/*
	123.123123:float64
*/
/*
	false:bool
*/
var ToBe bool = false
var c float64 = 123.123123
var d []int
type intAlias int
func main() {
	/*
		"Hello World":string
	*/
	print("Hello World")
	/*
		d:[]int
	*/
	/*
  		append(d,3): []int
		d:[]int
		3:int
	*/
  	d = append(d,3)
	/*
		d:[]int
	*/
	/*
  		append(d,5): []int
		d:[]int
		5:int
	*/
  	d = append(d,5)
	/*
		d:[]int
	*/
	/*
  		append(d,10): []int
		d:[]int
		10:int
	*/
  	d = append(d,10)
}
