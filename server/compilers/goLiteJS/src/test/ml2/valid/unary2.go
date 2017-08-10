// unary operations on aliases of basic types
package main

type num int
type double float64
type boolean bool
type char rune

var n num = num(23)
var x double = double(23.0)
var p boolean = boolean(true)
var a char = char('a')

var m num
var y double
var q boolean
var b char

func main() {
    m = num(+n)
    y = double(+x)
    b = char(+a)

    m = num(-n)
    y = double(-x)
    b = char(-a)

    q = boolean(!p)

    m = num(^n)
    b = char(^a)

}
