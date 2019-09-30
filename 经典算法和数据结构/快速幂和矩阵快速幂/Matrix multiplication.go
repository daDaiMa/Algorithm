package main

import "fmt"

// 本函数只能给同阶方阵使用
func mul(ma, mb [][]int) [][]int {
	size := len(ma)
	res := make([][]int, size)
	for i := 0; i < size; i++ {
		res[i] = make([]int, size)
	}

	for i := 0; i < size; i++ {
		for j := 0; j < size; j++ {
			res[i][j] = 0
			for k := 0; k < size; k++ {
				res[i][j] += ma[i][k] * mb[k][j]
			}
		}
	}

	return res
}

func main() {
	ma := [][]int{{6, -8, -8, 16}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}}
	mb := [][]int{{6, -8, -8, 16}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}}
	fmt.Println(mul(ma, mb))
}
