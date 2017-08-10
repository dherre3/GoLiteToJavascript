// basic types as return values
package main

func fvoid() {
    return
}

func fint() int {
    return 23 + 23
}

func ffloat64() float64 {
    return 23.0 + 23.0
}

func fbool() bool {
    return true || false
}

func frune() rune {
    return 'a'
}

func fstring() string {
    return "asdf" + "asdf"
}

func main() {
    fint()
    ffloat64()
    fbool()
    frune()
    fstring()
}
