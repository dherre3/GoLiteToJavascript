package main

func main() {
  println(fibonacci(0))
  println(fibonacci(1))
  println(fibonacci(2))
  println(fibonacci(3))
  println(fibonacci(4))
  println(fibonacci(5))
}

func fibonacci(n int) int {
  // computes the nth fibonacci number

  if n == 0 || n == 1 {
    return n
  }

  a := 0
  b := 1

  for i := 0; i < n - 1; i++ {
    temp := a
    a = b
    b = temp + b
  }

  return b
}
