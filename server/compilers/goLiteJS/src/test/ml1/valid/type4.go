// type declaration in for block
package main

func main() {
    for {
        type num int

        type (
            num int
            word string
        )

    }
}
