// shadowing basic type variables
package main

var n int = 23
var x float64 = 23.0
var p bool = true
var a rune = 'a'
var s string = "asdf"

func main() {
    if true {
        var n int = 32
        var x float64 = 32.0
        var p bool = false
        var a rune = 'b'
        var s string = "fdsa"
    } else if false {
        var n int = 32
        var x float64 = 32.0
        var p bool = false
        var a rune = 'b'
        var s string = "fdsa"
    } else {
        var n int = 32
        var x float64 = 32.0
        var p bool = false
        var a rune = 'b'
        var s string = "fdsa"
    }
}
