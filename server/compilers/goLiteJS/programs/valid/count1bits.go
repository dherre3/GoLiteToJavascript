package main

func main() {
  println(count1Bits(3))
  println(count1Bits(9))
  println(count1Bits(1036))
  println(count1Bits(2017))
  println(count1Bits(0))
}

func count1Bits(n int) int {
  // counts the number of bits set to 1 in an integer n

  count := 0

  for n != 0 {
    if n & 1 == 1 {
      count += 1
    }

    n >>= 1
  }

  return count
}
