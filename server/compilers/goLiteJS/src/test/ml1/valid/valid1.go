package main

func firstSyntaxError() {

	/*var fe string = `\n`*/
	var hello [0777]int
	type (
		num   int
		point struct {
			x, y float64
		}
	)
}

func secondSyntaxError(_, c int) bool {
	return
}

func secondSyntaxError(b float, c int) bool {
	return
}
