package main

func cast_int() {
	type num int
	var x int = 5
	var y num = num(x)
	x = int(y)
	println(x)
}

func cast_float64() {
	type num float64
	var x float64 = 5.0
	var y num = num(x)
	x = float64(y)
	println(x)
}

func cast_rune() {
	type num rune
	var x rune = 'z'
	var y num = num(x)
	x = rune(y)
	println(x)
}

func cast_bool() {
	type num bool
	var x bool = true
	var y num = num(x)
	x = bool(y)
	println(x)
}

func main() {
	cast_int()
	cast_rune()
	cast_bool()
}
