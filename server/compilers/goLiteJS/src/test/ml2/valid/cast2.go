// casting aliases of base types
package main

type num int
type double float64
type boolean bool
type char rune

var n num = num(23)
var x double = double(23.0)
var p boolean = boolean(true)
var a char = char('a')

var m num = num(n)
var y double = double(x)
var q boolean = boolean(p)
var b char = char(a)

var l int = int(m)
var z float64 = float64(y)
var r bool = bool(q)
var c rune = rune(b)
