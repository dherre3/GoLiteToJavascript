// statement after does not type check
package main

var n int

func main() {
    return
    n = 23.0
}
