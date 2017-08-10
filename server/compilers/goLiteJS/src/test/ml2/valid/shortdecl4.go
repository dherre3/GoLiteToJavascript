// short declarations in init shadowing current scope
package main

func main() {
    var l, m, n int = 1, 2, 3

    for l:=0; l < 23; l++ {

    }

    if m := 0; true {

    }

    switch n:=0; n {
    default:
    }
}
