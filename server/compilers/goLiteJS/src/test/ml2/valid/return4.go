// type checking statements after return
package main

var n int
var x float64
var p bool
var a rune
var s string

func main() {
    return
    n = 23
    x = 23.0
    p = true
    a = 'a'
    s = "asdf"
}
