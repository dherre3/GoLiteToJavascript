// shadowing type declarations
package main

type num int
var a num

func main() {
    type num float64
    a = num(23)
    var b num
    b = num(23.0)
    if true {
        type num rune
        var c num
        c = num('a')
    } else if false {
        type num rune
        var c num
        c = num('a')
    } else {
        type num rune
        var c num
        c = num('a')
    }
    var d num
    d = num(23.0)
}
