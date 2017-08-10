// aliases of basic types as return values
package main

type num int
type double float64
type boolean bool
type char rune

func fnum() num {
    return num(23)
}

func fdouble() double {
    return double(23.0)
}

func fboolean() boolean {
    return boolean(true)
}

func fchar() char {
    return char('a')
}


func main() {
    fnum()
    fdouble()
    fboolean()
    fchar()
}
