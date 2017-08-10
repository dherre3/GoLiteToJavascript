// parameter in function call does not type check
package main

func f(a int) {}

func main() {
    f(23.0)
}
