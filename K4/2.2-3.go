package main
import (
	"fmt"
	"time"
)


func main() {
	start := time.Now()
	var a, b, tmp int = 1, 1, 0
	n := 50
	fmt.Printf("F(1)=1\n");
	for i := 2; i <= n; i++ {
		tmp = a
		a = b
		b = tmp + b
		fmt.Printf("F(%v)=%v\n", i, a)
	}
	elapsed := time.Since(start)
	fmt.Println("Run time:", elapsed)
}