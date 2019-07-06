
func generateMatrix(n int) [][]int {
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = make([]int, n)
	}

	count := 1
	x := 0
	y := 0

	for count <= n*n {

		for count <= n*n{
			matrix[y][x] = count
			count++
			if  x+1 >= n || matrix[y][x+1] != 0 {
				y++
				break
			} else {
				x++
			}
		}

		for count <= n*n{
			matrix[y][x] = count
			count++
			if  y+1 >= n || matrix[y+1][x] != 0 {
				x--
				break
			} else {
				y++
			}
		}

		for count <= n*n{
			matrix[y][x] = count
			count++
			if x-1 < 0 || matrix[y][x-1] != 0 {
				y--
				break
			} else {
				x--
			}
		}

		for count <= n*n{
			matrix[y][x] = count
			count++
			if  y-1 < 0 || matrix[y-1][x] != 0 {
				x++
				break
			} else {
				y--
			}
		}

	}

	return matrix

}
