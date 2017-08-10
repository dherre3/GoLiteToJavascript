// short declarations shadowing outer scope
package main

var n int = 32
var x float64 = 32.0
var p bool = false
var a rune = 'b'
var s string = "fdsa"

func main() {
    n, x, p, a, s := 23, 23.0, true, 'a', "asdf"
}
