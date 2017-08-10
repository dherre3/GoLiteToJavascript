package main

type intalias int
type float64alias float64
type runealias rune
type boolalias bool

func main() {
  if float64(3) != 3. {
    print("error")
  }

  if float64(3.1) != 3.1 {
    print("error")
  }

  if int(3.4) != 3 {
    print("error")
  }

  if rune(65) != 'A' {
    print("error")
  }

  if rune(65.5) != 'A' {
    print("error")
  }

  if int(rune(5.8)) != 5 {
    print("error")
  }

  if !bool(4) {
    print("error")
  }

  if bool(0) {
    print("error")
  }


  // with type aliases

  if float64alias(3) != float64alias(3.) {
    print("error")
  }

  if float64alias(3.1) != float64alias(3.1) {
    print("error")
  }

  if intalias(3.4) != intalias(3) {
    print("error")
  }

  if runealias(65) != runealias('A') {
    print("error")
  }

  if runealias(65.5) != runealias('A') {
    print("error")
  }

  if intalias(runealias(5.8)) != intalias(5) {
    print("error")
  }

  if !boolalias(4) {
    print("error")
  }

  if boolalias(0) {
    print("error")
  }
}
