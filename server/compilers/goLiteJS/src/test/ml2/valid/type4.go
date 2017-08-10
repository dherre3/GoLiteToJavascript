// alias of basic types in structs
package main

type num int
type double float64
type boolean bool
type char rune

type type_struct struct {
    n num
    x double
    p boolean
    a char
}

var ts type_struct

func main() {
    ts.n = num(23)
    ts.x = double(23.0)
    ts.p = boolean(true)
    ts.a = char('a')
}
