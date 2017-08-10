// Try to access fields of a variable when:
// - it is declared as a struct (s)
// - it is declared as an alias to a struct (p)
// - it is declared as an alias to an alias to a struct (q)
//
// Also try to put aliased fields inside a struct

package main

type point struct {
	x, y, z int
}

type indirect_point point

type vector struct {
	i indirect_point
	j indirect_point
}

func main() {
	var a bool
	var b int
	var c string

	var s struct {
		a bool
		b int
		c string
	}
	s.a = true
	println(s.a)
	s.b = 42
	println(s.b)
	s.c = "struct"
	println(s.c)

	a = s.a
	println(a)
	b = s.b
	println(b)
	c = s.c
	println(c)

	var x, y, z int

	var p point
	p.x = 0
	p.y = -1
	p.z = 1

	x = p.x
	y = p.y
	x = p.z

	var q indirect_point
	q.x = 0
	q.y = -1
	q.z = 1

	x = q.x
	y = q.y
	z = q.z

	var v vector
	v.i = q
	v.j = q

	v.i.x = 2
	v.i.y = 3
	v.i.z = 4

	x = v.i.x
	println(x)
	y = v.i.y
	println(y)
	z = v.i.z
	println(z)
}
