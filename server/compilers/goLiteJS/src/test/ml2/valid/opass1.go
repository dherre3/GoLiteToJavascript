// op assignment
package main

var n int = 23
var x float64 = 23.0
var p bool = true
var a rune = 'a'
var s string = "asdf"

func main() {
    n += n
    x += x
    s += s
    a += a

    n -= n
    x -= x
    a -= a

    n *= n
    x *= x
    a *= a

    n /= n
    x /= x
    a /= a

    n %= n
    n &= n
    n |= n
    n ^= n
    n %= n
    n >>= n
    n <<= n
}
