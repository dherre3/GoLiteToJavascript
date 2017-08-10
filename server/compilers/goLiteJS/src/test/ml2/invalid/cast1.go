// casting aliases of aliases
package main

type num int
type anum num

var n num = 23
var m anum = anum(n)
