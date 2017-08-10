package main

func main() {
  print(isPrime(2017))
}

func isPrime(n int) bool {
  // return whether or not int n is a prime number
  
  for i := 2; i < n/2; i++ {
    if n % i == 0 {
      return false
    }
  }

  return true
}
