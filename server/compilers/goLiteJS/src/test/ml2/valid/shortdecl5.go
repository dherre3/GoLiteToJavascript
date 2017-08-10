// short declarations in init shadowing current scope
// redeclare variable in control structure body
package main

func main() {
    var l, m, n int = 1, 2, 3

    for l:=0; l < 23; l++ {
        var l float64 = 23.0
    }

    if m := 0; true{
        var m rune = 'a'
    }

    switch n:=0; n {
    default: var n string = "asdf"
    }
}
