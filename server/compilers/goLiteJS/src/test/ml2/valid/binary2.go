// binary operations on aliases of basic types
package main

type num int
type double float64
type boolean bool
type char rune

var n num = num(23)
var x double = double(23.0)
var p boolean = boolean(true)
var a char = char('a')

var m num
var y double
var q boolean
var b char

func main() {
    q = boolean(p || p)
    q = boolean(p && p)

    q = boolean(p == p)
    q = boolean(n == n)
    q = boolean(x == x)
    q = boolean(a == a)

    q = boolean(p != p)
    q = boolean(n != n)
    q = boolean(x != x)
    q = boolean(a != a)

    q = boolean(n < n)
    q = boolean(x < x)
    q = boolean(a < a)

    q = boolean(n <= n)
    q = boolean(x <= x)
    q = boolean(a <= a)

    q = boolean(n > n)
    q = boolean(x > x)
    q = boolean(a > a)

    q = boolean(n >= n)
    q = boolean(x >= x)
    q = boolean(a >= a)


    y = double(x + x)
    y = double(x - x)
    y = double(x * x)
    y = double(x / x)

    m = num(n + n)
    m = num(n - n)
    m = num(n * n)
    m = num(n / n)
    m = num(n % n)
    m = num(n | n)
    m = num(n & n)
    m = num(n << n)
    m = num(n >> n)
    m = num(n &^ n)
    m = num(n ^ n)

    b = char(a + a)
    b = char(a - a)
    b = char(a * a)
    b = char(a / a)
    b = char(a % a)
    b = char(a | a)
    b = char(a & a)
    b = char(a << a)
    b = char(a >> a)
    b = char(a &^ a)
    b = char(a ^ a)
}
