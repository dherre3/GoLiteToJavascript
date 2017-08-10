package main

type intalias int
type float64alias float64
type runealias rune
type boolalias bool
type stringalias string

type mystruct struct {
  i int
  b bool
  f float64
  r rune
  s string
}

func main() {
  {
    var i int
    var b bool
    var f float64
    var r rune
    var s string
    //Check for variable correct variable initializations
    if i != 0 || b != false || f != 0.0 || int(r) != 0 || s != "" {
      print("error")
    }
  }

  {
    var i intalias
    var b boolalias
    var f float64alias
    var r runealias
    // Check for aliases, can't check string aliases since we can't typecast

    if int(i) != 0 || bool(b) != false || float64(f) != 0.0 || int(r) != 0 {
      print("error")
    }
  }
  //Check for struct initializations
  {
    var s mystruct
    if s.i != 0 || s.b != false || s.f != 0.0 || int(s.r) != 0 || s.s != "" {
      print("error")
    }
  }

  //Check for array initializations
  {
    var i [3]int
    var b [3]bool
    var f [3]float64
    var r [3]rune
    var s [3]string

    if i[0] != 0 || i[1] != 0 || i[2] != 0 {
      print("error")
    }
    if b[0] != false || b[1] != false || b[2] != false {
      print("error")
    }
    if f[0] != 0.0 || f[1] != 0.0 || f[2] != 0.0 {
      print("error")
    }
    if int(r[0]) != 0 || int(r[1]) != 0 || int(r[2]) != 0 {
      print("error")
    }
    if s[0] != "" || s[1] != "" || s[2] != "" {
      print("error")
    }
  }
  
}
