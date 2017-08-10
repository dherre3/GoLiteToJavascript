// aliases of base types in short declarations
package main

type num int
type double float64
type boolean bool
type char rune

func main() {
    n, x := num(23), double(23.0)
    p, a :=  boolean(true), char('a')
}
