package main 

type mystruct struct {
  a int
}

func main() {
  {
    // struct comparison
    var s1, s2 mystruct
    s1.a = 1
    s2.a = 1

    if s1 != s2 {
      print("error")
    }

    s1.a = 3
    if s1 == s2 {
      print("error")
    }
  }

  {
    // array comparison
    var a1, a2 [4]string
    a1[0] = "1"
    a2[0] = "1"

    if a1 != a2 {
      print("error")
    }

    a2[0] = "2"
    if a1 == a2 {
      print("error")
    }
  }

  {
    // int comparison
    i1, i2 := 3, 003

    if i1 != i2 {
      print("error")
    }
  }

  {
    // float comparison
    f1, f2, f3 := 3.0, 3., 3.0000

    if f1 != f2 || f2 != f3 {
      print("error")
    }
  }

  {
    // string comparison
    s1, s2 := "hello", "hello"

    if s1 != s2 {
      print("error")
    }

    s1 = " hello"
    if s1 == s2 {
      print("error")
    }

    s1, s2 = `\nfoo`, "\nfoo"

    if s1 == s2 {
      print("error")
    }

    s2 = "\\nfoo"
    if s1 != s2 {
      print("error")
    }
  }
}
