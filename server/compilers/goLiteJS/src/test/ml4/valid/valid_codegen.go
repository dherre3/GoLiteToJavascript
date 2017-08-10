package main

func f1(a int) {
  println(a)
}

func f2(a bool, b string) {
  println(a, b)
}

func f3() {
  println("empty")
}

func f4(a int) int {
  return a * 2
}

func f5() {
  return
}

func f6(a int) string {
  if a % 2 == 0 {
    return "even"
  } else if a == 1 {
    return "1"
  } else {
    return "odd"
  }
}

func f7(a int) string {
  if a % 2 == 0 {
    return "even"
  } else if a == 1 {
    return "1"
  } else {
    return "odd"
  }
}

func main() {

  {
    // short decl
    b, c := 3, 5
    println(b)
    println(c)
  }

  {
    b, c := 3, 5
    println(b, c)
  }

  {
    var b, c = 3, 5
    println(b, c)
  }

  {
    var b int = 3
    var c int = 98
    println(b, c)
  }

  {
    b, c := 3, 5
    println(b, c)
    b, c = c, b
    println(b, c)
    c, b = b, 98
    println(b, c)
    b, c = b, 98
    println(b, c)
  }

  {
    if a := 3; a < 9 {
      println("helo")
    } else if a := 3; a < 9 {
      println("helo2")
    } else if a := 3; a < 9 {
      println("helo3")
    } else {
      println("helo4")
    }

  }

  {
    for a, b := 6, 8; a < 9; a++ {
      println("loopy")
      println(b)
    }
  }

  {
    var a [3]int
    a[1] = 98

    println(a[1])
  }

  {
    println()
    print()
  }

  {
    var a [3]int
    var b = a
    a[1] = 98

    println(a[1])
    println(b[1])
  }

  {
    var a []int
    a = append(a, 98)
    var b = a

    println(a[0])
    println(b[0])
  }

  {
    var a []int
    a = append(a, 100)
    var b = append(a, 98)
    a[0] = 3

    println(a[0])
    println(b[0])
  }

  {
    switch (90) {
    case 90, 91:
      println(90, 91);
    case 300, 19:
      println(300, 19);
    }
  }

  {
    f1(9)
    f2(true, "Hllo")
    (((((f3)))))()
  }

  {
    var s = "YOOO"
    println("hello" + s)
    println("hell" + "helksdfj" + s)
    var a = "hell" + "helksdfj"
    println(a)
  }

  {
    var a []int
    a = append(a, 3)
    println(a[0])
    var b = append(a, 9)
    a[0] = 1
    println(a[0])
    println(b[0])
  }

  {
    switch {
      case 3 < 9: println("3 < 9")
      case 1 < 9: println("1 < 9")
      case false: println("1 < 9")
    }
  }

  {
    switch 3 {
    case 9: println(8)
    default: println("default")
    case 8: println(98)
    }
  }

  {
    switch (3 + 98) {
    case 98 + 11: println("98 + 11")
    case 98 + 3: println("98 + 3")
    case 98 + 1: println("98 + 1")
    }
  }

  {
    var a = 3 - (1 + 98)
    println(a)
  }

  {
    // binary operators
    println(false || true)
    println(false || false)
    println(false && false)
    println(true && true)
    println("hello" == "hello")
    println("hello" != "hello")
    println(41 != 31)
    println(41 == 31)
    println(41 != 41)
    println(914 > 41)
    println(914 < 413051)
    println(914 <= 413051)
    println(914 >= 413051)
    println('a' + 'b' + 'c')
    println(4 + 13 + 3)
    println("sldfj" + "klsdjf" + "lksdfj")
    println('a' - 'b' - 'c')
    println(4 - 13 - 3)
    println('a' * 'b' * 'c')
    println(4 * 13 * 3)
    println('a' / 'b' / 'c')
    println('a' / 'b')
    println(4 / 13 / 3)
    println(-4 / 13)
    println(((f4))(31) / 3)
    println('a' % 'b' % 'c')
    println(4 % 13 % 3)
    println('a' | 'b' | 'c')
    println(4 | 13 | 3)
    println(1 | -1)
    println('a' & 'b' & 'c')
    println(4 & 13 & 3)
    println('a' << '\t')
    println(4 << 1)
    println('a' >> '\t')
    println(4 >> 1)
    println('a' &^ 'b' &^ 'c')
    println(4 &^ 13 &^ 3)
    println('a' ^ 'b' ^ 'c')
    println(4 ^ 13 ^ 3)
  }

  {
    // opassign
    {
      var a = 3
      a += 13
      println(a)

      var b = 'a'
      b += 'c'
      println(b)

      var c = "hello"
      c += " world!"
      println(c)
    }

    {
      var a = 3
      a -= 13
      println(a)

      var b = 'a'
      b -= 'c'
      println(b)
    }

    {
      var a = 3
      a += 13
      println(a)

      var b = 'a'
      b += 'c'
      println(b)
    }

    {
      var a = 3
      a *= 13
      println(a)

      var b = 'a'
      b *= 'c'
      println(b)
    }

    {
      var a = 3
      a /= 13
      println(a)

      var b = 'a'
      b /= 'c'
      println(b)

      var c = -3
      c /= 13
      println(c)

      var d = ((f4))(31)
      d /= 3
      println(d)
    }

    {
      var a = 3
      a %= 13
      println(a)

      var b = 'a'
      b %= 'c'
      println(b)
    }

    {
      var a = 3
      a |= 13
      println(a)

      var b = 'a'
      b |= 'c'
      println(b)
    }

    {
      var a = 3
      a &= 13
      println(a)

      var b = 'a'
      b &= 'c'
      println(b)
    }

    {
      var a = 4
      a <<= 1
      println(a)

      var b = 'a'
      b <<= '\t'
      println(b)
    }

    {
      var a = 4
      a >>= 1
      println(a)

      var b = 'a'
      b >>= '\t'
      println(b)
    }

    {
      var a = 3
      a &^= 13
      println(a)

      var b = 'a'
      b &^= 'c'
      println(b)
    }

    {
      var a = 3
      a ^= 13
      println(a)

      var b = 'a'
      b ^= 'c'
      println(b)
    }
  }

  {
    // unary operators
    println(-3)
    println(+7)
    println(^91)
    println(^-91)
    println(!true)
    println(!false)
    println(!!!!!(false && true))
  }

  {
    // increment decrement
    {
      var a = 3
      a++
      println(a)
      a--
      a--
      println(a)
    }
    {
      var a = -3
      a++
      println(a)
      a--
      a--
      println(a)
    }
    {
      var a = 'a'
      a++
      println(a)
      a--
      a--
      println(a)
    }
  }

  {
    for a := 1; a < 10; a++ {
      if a % 2 == 0 {
        continue
      }

      println(a)
    }
  }

  {
    a := 3
    for {
      if (a > 3) {
        break
      }

      a++
    }
  }

  {
    for a:= 3; ; {
      println(a)

      if a == 4 {
        break;
      }

      a++
    }
  }

  {
    a := 5

    for a < 9 {
      println(a)

      a++
    }
  }

  {
    var a = f4(98)
    println(a)
    println(f4(981435))
  }

  {
    f5()
    println("f5")
  }

  {
    println(f6(16))
    println(f6(17))
  }

  {
    println(f7(2))
    println(f7(1))
    println(f7(3))
  }

  {
    var a [3]int
    a[0] = 3
    a[1] = 5
    a[2] = 8

    a[0] *= a[1]
    a[1] *= a[2]
    a[2] *= a[0]

    println(a[0])
    println(a[1])
    println(a[2])
  }

  {
    var a [3]int
    a[0] = 3
    a[1] = 5
    a[2] = 8

    a[2] /= a[0]

    println(a[0])
    println(a[1])
    println(a[2])
  }

  {
    a, b, _, d, e := 3, 1, 4, 5, 6
    println(a, b, d, e)
  }

  {
    var a = 84

    {
      println(a)
      var a = a
      println(a)
    }
  }

  {
    f1 := 3
    println(f1)
  }

  {
    var a = 84;

    {
      var a = 3;

      a, b, _, d, e := 3, 1, 4, 5, 6
      println(a, b, d, e)
    }

    println(a)
  }

  {
    var true = 3
    println(3)
    println(true)
  }
}
