package main

var a struct {
	a int
}
var b struct {
	a int
}

func main() {
	a = b // legal
}

