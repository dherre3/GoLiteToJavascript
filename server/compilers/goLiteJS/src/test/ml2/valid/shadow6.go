// shadowing type declarations
package main

type num int
var a num

func main() {
    type num float64
    a = num(23)
    var b num
    b = num(23.0)
}
