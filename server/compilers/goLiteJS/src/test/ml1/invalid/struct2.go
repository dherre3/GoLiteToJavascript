// typo in field access
package main

type point struct {
        x, y, z int
}

var p point

func main() {
    p,x = 1
}
