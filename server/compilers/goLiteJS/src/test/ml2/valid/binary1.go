// binary operations on basic types
package main

var n int = 23
var x float64 = 23.0
var p bool = true
var a rune = 'a'
var s string = "asdf"

var m int
var y float64
var q bool
var b rune
var t string

func main() {
    q = p || p
    q = p && p

    q = p == p
    q = n == n
    q = x == x
    q = a == a
    q = s == s

    q = p != p
    q = n != n
    q = x != x
    q = a != a
    q = s != s

    q = n < n
    q = x < x
    q = a < a
    q = s < s

    q = n <= n
    q = x <= x
    q = a <= a
    q = s <= s

    q = n > n
    q = x > x
    q = a > a
    q = s > s

    q = n >= n
    q = x >= x
    q = a >= a
    q = s >= s

    t = s + s

    y = x + x
    y = x - x
    y = x * x
    y = x / x

    m = n + n
    m = n - n
    m = n * n
    m = n / n
    m = n % n
    m = n | n
    m = n & n
    m = n << n
    m = n >> n
    m = n &^ n
    m = n ^ n

    b = a + a
    b = a - a
    b = a * a
    b = a / a
    b = a % a
    b = a | a
    b = a & a
    b = a << a
    b = a >> a
    b = a &^ a
    b = a ^ a
}
