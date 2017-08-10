// bunch of random stuff
package main

type num int

func myfunc(a int, b string) {

}

func myfunc1() {

}

func myfunc2(a int, b string) {
  (((myfunc1)))()
  myfunc(34, "lskdf")
  (((myfunc)))(a, b)

  x, y := 34, "lksdjf"
  (((myfunc2)))(x, y)
  (((myfunc2)))(a, b)
}

func main() {
  {
    var a int
    a, b, c := 3, 1, 3
  }

  {
    var b (int) = 3
  }

  {
    var a [3]int
    var b [3]int = a
  }

  {
    type num int
    type n num
    var a n = -n(3)
  }


  {
    b := 3
    b += 3
  
    b, _ = 3, 4
  }
  
  {
    var _ int = 3
  }

  for a := 3; a < 3; a++ {
    print("hello")
  }

  if a := 3; 3 < 9 {
    print("hello")
  } else if 3 > 3 {
    print("hello")
  }

  switch a := 3; {
  case bool(3):
    a := "89"
    break;
  case bool(2):
    break;
  case bool(2):
    break;
  }

  {
    var a struct {
      a int
      b int
      z struct {
        a, b int
      }
    }

    var b struct {
      a, b int
      z struct {
        a int
        b int
      }
    }

    a = b
  }

  {
    var a [3]num
    var b [3]num
    c := a == b
  }

  {
    myfunc1 := 3
  }

  {
    var a int
    if a := 3; a < 4 {}
    switch a := 3; {}
    for a := 3; ; {}
  }

  {
    var a bool
    {
      a := "string"
      for a := 3; a < 3; a++ {
        a := 3.1
      }
    }
  }
}
