package main 
//Array types are passed by value while structs and slices are passed by reference
type mystruct struct { 
  i int
}

type intslice []int

func changeFirstArrayVal(arr [5]int) {
  arr[0] = -1
}

func changeFirstSliceVal(slice []int) {
  slice[0] = -1
}

func changeFirstSliceAliasVal(slice intslice) {
  slice[0] = -1
}

func changeStructFieldVal(stru mystruct) {
  stru.i = -1
}

func main() {
  var arr [5]int
  arr[0] = 1

  var sli []int
  sli = append(sli, 1)

  var sli2 intslice
  sli2 = append(sli2, 1)

  var stru mystruct
  stru.i = 1

  changeFirstArrayVal(arr)
  if arr[0] != 1 {
    print("error")
  }

  changeFirstSliceVal(sli)
  if sli[0] == 1 {
    print("error")
  }

  changeFirstSliceAliasVal(sli2)
  if sli2[0] == 1 {
    print("error")
  }

  changeStructFieldVal(stru)
  if stru.i != 1 {
    print("error")
  }
}

