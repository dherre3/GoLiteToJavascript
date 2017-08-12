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
		"dadas	":string
	*/
	/*
		`
    `:string	*/
	/*
		'	':rune	*/
	a, v, h := "dadas	", `
    `, '	';
	var t struct{
			b int
			nb intAlias
		}

	/*
		d:[]int
	*/
	/*
  		append(d,3): []int
		d:[]int
		3:int
	*/
  	d = append(d,3)
}
