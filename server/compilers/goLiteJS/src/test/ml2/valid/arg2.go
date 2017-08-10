// aliases of base types as function arguments
package main

type num int
type double float64
type boolean bool
type char rune

func fnum(n num) {
    return
}

func fdouble(x double) {
    return
}

func fboolean(p boolean) {
    return
}

func fchar(a char) {
    return
}

func main() {
    fnum(num(23))
    fdouble(double(23.0))
    fboolean(boolean(true))
    fchar(char('a'))
}
