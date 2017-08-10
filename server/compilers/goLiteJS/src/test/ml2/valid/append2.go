// append expressions with alises in e2
package main

var ints []int
var floats []float64
var bools []bool
var runes []rune

type num int
type double float64
type boolean bool
type char rune

var n num = num(23)
var x double = double(23.0)
var p boolean = boolean(true)
var a char = char('a')

func main() {
    ints = append(ints, n)
    floats = append(floats, x)
    bools = append(bools, p)
    runes = append(runes, a)
}
