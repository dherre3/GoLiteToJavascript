package main


func main() {
	var arr [3]int
	
	var w [][3]int
	arr[0]=0
	w = append(w,arr)
	w[0][0] = 1
	println(arr[0], w[0][0])
	var x []int 
	x = append(x,1)
	y:= append(x,0)
	z:=append(x,1)
	println(y[1])
	println(z[1])	
}
