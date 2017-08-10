// indexing slices and arrays of aliases of aliases
package main

type index int

type num int
type double float64
type boolean bool
type char rune
type word string

type anum num
type adouble double
type aboolean boolean
type achar char
type aword word

var ints []anum
var floats []adouble
var bools []aboolean
var runes []achar
var words [23]aword

var n int = 23
var ind index = index(23)

func main() {
    _ = ints[23]
    _ = floats[n]
    _ = bools[ind]
    _ = words [2+3]
    _ = words[23] // index out of bounds is runtime error
}
