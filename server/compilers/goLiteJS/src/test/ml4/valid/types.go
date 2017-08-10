package main

type intalias int
type float64alias float64
type runealias rune
type boolalias bool

func main() {
  if float64(3) != 3. {
    print("error 1")
  }

  if float64(3.1) != 3.1 {
    print("error 2")
  }

  // if int(3.4) != 3 {
  //   print("error 3")
  // }

  if rune(65) != 'A' {
    print("error 4")
  }

  // if rune(65.5) != 'A' {
  //   print("error 5")
  // }

  // if int(rune(5.8)) != 5 {
  //   print("error 6")
  // }

  // if !bool(4) {
  //   print("error 7")
  // }

  // if bool(0) {
  //   print("error 8")
  // }


  // with type aliases

  // if float64alias(3) != float64alias(3.) {
  //   print("error 9")
  // }

  // if float64alias(3.1) != float64alias(3.1) {
  //   print("error 10")
  // }

  // if intalias(3.4) != intalias(3) {
  //   print("error 11")
  // }

  if runealias(65) != runealias('A') {
    print("error 12")
  }

  // if runealias(65.5) != runealias('A') {
  //   print("error 13")
  // }

  // if intalias(runealias(5.8)) != intalias(5) {
  //   print("error 14")
  // }

  // if !boolalias(4) {
  //   print("error 15")
  // }

  // if boolalias(0) {
  //   print("error 16")
  // }
}
