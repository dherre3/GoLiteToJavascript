// array index does not type check in declaration
package main

var x [1.0]int

func main() {
    x[0] = 1
}
