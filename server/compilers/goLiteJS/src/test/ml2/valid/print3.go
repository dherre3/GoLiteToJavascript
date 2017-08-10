//print and println of aliases of base types
package main

type num int
type double float64
type boolean bool
type char rune

var n num = num(23)
var x double = double(23.0)
var p boolean = boolean(true)
var a char = char('a')

func main() {
    print(n, x, p, a)
    println(n, x, p, a)
}
