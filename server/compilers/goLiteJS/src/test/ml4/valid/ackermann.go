// Ackermann function
package main

func A(m, n int) int {
    if m < 0 || n < 0 {
        println("arguments must be non-negative integers")
        return -1
    }

    if m == 0 {
        return n + 1
    } else if n == 0 {
        return A(m - 1, 1)
    } else {
        return A(m - 1, A(m, n - 1))
    }
}

func main() {
    println("A(0, 0) =", A(0, 0))
    println("A(0, 1) =", A(0, 1))
    println("A(1, 0) =", A(1, 0))
    println("A(1, 1) =", A(1, 1))
    // println("A(3, 20) =", A(3, 20))
    // println("A(5, 6) =", A(5, 6))
    // println("A(-1, 0) =", A(-1, 0))
    // println("A(0, -1) =", A(0, -1))
    return
}
