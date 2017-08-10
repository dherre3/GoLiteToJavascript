package main

func assign_int() {
	var a, b int
	a = b

	type num int
	var c, d num
	c = d
	print(c,a)
}

func assign_rune() {
	var a, b rune
	a = b

	type r rune
	var c, d r
	c = d
	print(c,a)
}

func assign_float64() {
	var a, b float64
	a = b

	type num float64
	var c, d num
	c = d
	print(c,a)
}

func assign_bool() {
	var a, b bool
	a = b

	type boolean bool
	var c, d boolean
	c = d
	print(c,a)
}

func assign_string() {
	var a, b string
	a = b

	type s string
	var c, d s
	c = d
	print(c,a)
}

func assign_slice() {
	var a, b []int
	a = b
	type num int
	var c, d []num
	c = d

	type numi []int
	var e, f numi
	e = f
	e = append(e,4) 
	a = append(a,4) 
	c = append(c,num(4))
}

func assign_array() {
	var a, b [5]int
	a = b

	type num int
	var c, d [5]num
	c = d

	type numi [5]int
	var e, f numi
	e = f
	if c==d {
		print("c==d");
	} 
	if e==f {
		print("e==f");
	} 
	if a==b {
		print("a==b")
	}
}

func assign_struct() {
	var a, b struct {
		x int
	}
	a = b

	type num struct {
		x int
	}
	var c, d num
	c = d
	if c==d {
		print("e==f");
	} 
	if a==b {
		print("a==b")
	}
}

func assign_multiple() {
	var a, b int
	a, b = b, a
}

func main() {
	assign_array()
	assign_multiple()
	assign_int()
	assign_struct()
	assign_bool()
	//assign_float64()
	assign_rune()
}
