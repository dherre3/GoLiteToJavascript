package main 

func main() {


  {
    //Check for string equality
    var (
      a = "3"
      b = "4"
      c = "5"
    )
 

    if a != "3" || b != "4" || c != "5" {
      print("error")
    }
  }

  {
    //Check for variable declaration
    var a, b, c = 3, 4, 5

    if a != 3 || b != 4 || c != 5 {
      print("error")
    }
  }

    //Check for short declarations using expressions
  {
    a := 3
    var b, c = a, a
    if b != 3 || c != 3 {
      print("error")
    }
  }

  {
    b, c := 3, 4
    if b != 3 || c != 4 {
      print("error")
    }
  }

  {
    //Check for swapping in short declarations
    b, c := 3, 4
    (c), b = b, c

    if b != 4 || c != 3 {
      print("error")
    }
  }

  {
    var a, b, c = 3, 4, 5

    a, b, c = c, a, b

    if a != 5 || b != 3 || c != 4 {
      print("error")
    }
  }
}

