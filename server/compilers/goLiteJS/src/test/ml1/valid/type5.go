// type declaration in switch block
package main

func main() {
    switch {
    default:
        type num int

        type (
            num int
            word string
        )
    }
}
