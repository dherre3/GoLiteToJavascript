// append expressions with alises in e1
package main

type num int
type double float64
type boolean bool
type char rune

var ints []num
var floats []double
var bools []boolean
var chars []char

func main() {
    ints = append(ints, num(23))
    floats = append(floats, double(23.0))
    bools = append(bools, boolean(true))
    chars = append(chars, char('a'))
}
