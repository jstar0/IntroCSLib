package main
import (
	"fmt"
	"time"
)

var n int = 50
func fib(n int) int {
    if n <= 2 {
        return 1
    } else {
        return fib(n-1) + fib(n-2)
    }
}

func main() {
	start := time.Now()
	for i := 1; i <= n; i++ {
		fmt.Printf("F(%v)=%v\n", i, fib(i))
	}
	elapsed := time.Since(start)
	fmt.Println("Run time:", elapsed)
}