// Try to append to a slice when:

package main

func main() {
	var ws []int

	ws = append(ws,3);
	ws = append(ws,5);
	ws = append(ws,3);
	ws = append(ws,3);
	print(ws[0],ws[1],ws[2],ws[3])
}
