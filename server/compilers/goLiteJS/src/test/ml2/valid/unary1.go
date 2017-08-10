// unary operations on basic types
package main

var n int = 23
var x float64 = 23.0
var p bool = true
var a rune = 'a'

var m int
var y float64
var q bool
var b rune

func main() {
    m = +n
    y = +x
    b = +a

    m = -n
    y = -x
    b = -a

    q = !p

    m = ^n
    b = ^a
}
