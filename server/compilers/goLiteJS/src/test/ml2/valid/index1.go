// indexing slices and arrays of base types
package main

type index int

var ints [23]int
var floats [23]float64
var bools [23]bool
var runes [23]rune
var words []string

var n int = 23
var ind index = index(23)

func main() {
    ints[23] = 23
    floats[n] = 23.0
    bools[ind] = true
    runes[23+23] = 'a' //runtime error
    words[23] = "asdf"
}
