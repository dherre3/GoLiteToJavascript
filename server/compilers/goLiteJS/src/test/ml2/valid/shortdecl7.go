// shadowing with short declaration of aliases of base types
package main

type num int
type double float64
type boolean bool
type char rune

var n int
var x float64
var p bool
var a rune

func main() {
    n, x := num(23), double(23.0)
    p, a :=  boolean(true), char('a')
}
