// append expressions
package main

var ints []int
var floats []float64
var bools []bool
var runes []rune
var words []string

func main() {
    {
        var a = bool(0.1)
        print(a)
    }
    ints = append(ints, 23)
    floats = append(floats, 23.0)
    bools = append(bools, true)
    runes = append(runes, 'a')
    words = append(words, "asdf")
}
