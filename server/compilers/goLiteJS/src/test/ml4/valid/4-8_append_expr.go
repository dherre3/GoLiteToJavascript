// Try to append to a slice when:

package main

func main() {
	type slice []int
	type indirect_slice slice
	type elem int

	var ws indirect_slice
	var xs slice
	var ys []int
	var zs []elem

	var x elem
	var y int

	//ws = append(ws, x)
	ws = append(ws, y)
	println(ws[0])

	// xs = append(xs, x)
	xs = append(xs, y)
	println(xs[0])

	// ys = append(ys, x)
	ys = append(ys, y)
	println(ys[0])

	zs = append(zs, x)
	println(zs[0])
	// zs = append(zs, y)
}
