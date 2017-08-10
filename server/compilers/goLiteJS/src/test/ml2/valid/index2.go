// indexing slices and arrays of aliases of base types
package main

type index int

type num int
type double float64
type boolean bool
type char rune
type word string

var ints []num
var floats []double
var bools []boolean
var runes []char
var words [23]word

var n int = 23
var ind index = index(23)

func main() {
    _ = ints[23]
    _ = floats[n]
    _ = bools[ind]
    _ = runes[2+3]
    _ = words[23]
}
