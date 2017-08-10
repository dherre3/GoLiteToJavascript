// mismatched types in append statement
package main

var ints []int

func main() {
    ints = append(ints, 23.0)
}
