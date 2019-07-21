


func spiralOrder(matrix [][]int) []int {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return []int{}
	}
	a := len(matrix)    //height
	b := len(matrix[0]) //weight

	x := 0
	y := 0

	list := []int{}
	x_max := a - 1
	y_max := b
	count := 0

	for {
		for step := 0; step < y_max; step++ {
			list = append(list, matrix[x][y])
			y++
			count++
		}
		y_max--
		y--
		x++

		if count == a*b {
			break
		}

		for step := 0; step < x_max; step++ {
			list = append(list, matrix[x][y])
			x++
			count++
		}
		x_max--
		x--
		y--
		
		if count == a*b {
			break
		}

		for step := 0; step < y_max; step++ {
			list = append(list, matrix[x][y])
			y--
			count++
		}
		y_max--
		y++
		x--

		if count == a*b {
			break
		}

		for step := 0; step < x_max; step++ {
			list = append(list, matrix[x][y])
			x--
			count++
		}
		x_max--
		x++
		y++

		if count == a*b {
			break
		}
		
	}

	return list

}
