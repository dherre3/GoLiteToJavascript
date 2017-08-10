// array index does not type check in assignment
package main

var x [1]int

func main() {
    x[0.0] = 1
}
