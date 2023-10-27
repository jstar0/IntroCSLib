package main
import (
	"fmt"
	"time"
	"math"
)

var n int = 50
var result float64 = 0
func fib(n int) int {
    result = (1 / math.Sqrt(5)) * (math.Pow(((1 + math.Sqrt(5)) / 2), float64(n))) - (math.Pow(((1 - math.Sqrt(5)) / 2), float64(n)))
	return int(result)
}

func main() {
	start := time.Now()
	for i := 1; i <= n; i++ {
		fmt.Printf("F(%v)=%v\n", i, fib(i))
	}
	elapsed := time.Since(start)
	fmt.Println("Run time:", elapsed)
}