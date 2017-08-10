package main

func main() {
	// switch x := 0; x {
	// 	case 1:
	// 		x++
	// 		print(x)
	// 	case 2,3:
	// 		x++
	// 		print(x)
	// 	default:
	// 		x++
	// 		print(x)
	// }

	// switch x := 0; x {
	// 	case 1:
	// 		var x int
	// 		print(x)
	// 	case 2,3:
	// 		var x int
	// 		print(x)
	// 	default:
	// 		var x int
	// 		print(x)
	// }

	// switch {
	// 	case true: print(true)
	// 	case false:
	// }

	type num int
	switch x := 1; x {
		case 1: print(x)
		case 2,3: print(x)
	}
}
