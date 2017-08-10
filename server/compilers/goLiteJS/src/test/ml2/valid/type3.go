// basic types in structs
package main

type type_struct struct {
    n int
    x float64
    p bool
    a rune
    s string
}

var ts type_struct

func main() {
    ts.n = 23
    ts.x = 23.0
    ts.p = true
    ts.a = 'a'
    ts.s = "asdf"
    return
}
