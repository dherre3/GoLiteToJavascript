// type declaration in if block
package main

func main() {
    if exp1 {
        type num int

        type (
            num int
            word string
        )

    }
}
