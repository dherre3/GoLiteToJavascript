package main

func main() {
  println(isPalindrome("helllo", 6))
  println(isPalindrome("caaabaaac", 9))
  println(isPalindrome("detartrated", 11))
  println(isPalindrome("lskdjfa", 7))
  println(isPalindrome("tattarrattat", 12))
  println(isPalindrome("racecar", 7))
  println(isPalindrome("comp520", 7))
}

func isPalindrome(s string, len int) bool {
  // return whether or not string s of length len is a palindrome
  
  for i := 0; i < len/2; i++ {
    if s[i] != s[len - 1 - i] {
      return false
    }
  }

  return true
}
