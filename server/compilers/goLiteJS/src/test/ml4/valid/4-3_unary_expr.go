package main

func base_types() {
	var (
		a int
		c rune
		d string
		e bool
	)

	// Unary plus
	println(+a)
	println(+c)

	// Unary negation
	println(-a)
	println(-c)

	// Unary bit-not
	println(^a)
	println(^c)

	// Unary logical not
	println(!e)
	println(d)
}

func type_aliases() {
	type (
		t1 int
		t2 float64
		t3 rune
		t4 string
		t5 bool
	)
	var (
		a t1
		c t3
		d t4
		e t5
	)

	// Unary plus
	println(+a)
	println(+c)

	// Unary negation
	println(-a)
	println(-c)

	// Unary bit-not
	println(^a)
	println(^c)

	// Unary logical not
	println(!e)
	print(d)
}
func main() {
	type_aliases()
	base_types()

}
