// quicksort
package main


var A []int

func partition(A []int, low, hi int) int {
    pivot := A[hi]
    i := low - 1
    for j := low; j < hi; j++ {
        if A[j] <= pivot {
            i++
            A[i], A[j] = A[j], A[i]
        } else {
            A[i + 1], A[hi] = A[hi], A[i + 1]
        }
    }
    return i + 1
}

func qsort(A []int, low, hi int) {
    if low < hi {
        p := partition(A, low, hi)
        qsort(A, low, p - 1)
        qsort(A, p + 1, hi)
    }
}

func selectionSort(A []int, length int) {
    for i:=0;i<length;i++ {
        for j:=0;j<length;j++ {
            if A[i]<A[j] {
                temp:= A[j]
                A[j] = A[i]
                A[i] = temp 
            }
        }
    }
}

func main() {
    // initialize(A)
    for k:=100;k>=0;k-- {
    A = append(A,k);
    }
    
    print("array: " )
    for i := 0; i <= 100; i++{
        print(A[i])
        print(", ")
    }
    print("\n")
    //qsort(A, 0, 4)
    selectionSort(A,101)
    print("sorted: " )
    for i := 0; i <= 100; i++ {
        print(A[i])
        print(", ")
    }
    return
}
