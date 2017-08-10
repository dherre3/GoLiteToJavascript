package main

func max(a, b int) int {
  if (a > b) {
    return a
  } else {
    return b
  }
}

func greatestContiguousSubsequence(arr []int, len int) int {
  // computes the sum of the greatest contiguous subsequence in array arr of length len

  var (
    greatest []int
    maxSum int
  )

  greatest = append(greatest, arr[0])

  for i := 1; i < len; i++ {
    var greater int = max(greatest[i - 1] + arr[i], arr[i])
    greatest = append(greatest, greater)
    maxSum = max(greater, maxSum)
  }

  return maxSum
}


func main() {
  var sequence []int
  sequence = append(sequence, -2)
  sequence = append(sequence, 1)
  sequence = append(sequence, -3)
  sequence = append(sequence, 4)
  sequence = append(sequence, -1)
  sequence = append(sequence, 2)
  sequence = append(sequence, 1)
  sequence = append(sequence, -5)
  sequence = append(sequence, 4)

  println(greatestContiguousSubsequence(sequence, 9))
}
