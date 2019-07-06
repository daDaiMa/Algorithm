
var set [][]int
var vis []bool
var max_size int
var size int
var current []int

func permute(nums []int) [][]int {
	set = make([][]int, factorial(len(nums)))
	vis = make([]bool, len(nums))
	max_size = len(nums)
	current = make([]int, len(nums))
	size = 0
	recursive(nums, 0)
	return set
}

func factorial(n int) int {
	result := 1
	for n != 0 {
		result *= n
		n--
	}
	return result
}

func recursive(nums []int, depth int) {
	if depth == max_size {
		set[size] = make([]int, max_size)
		copy(set[size], current)
		// fmt.Println(size)
		// fmt.Println(set[size])
		size++
		return
	}

	for i := 0; i < max_size; i++ {
		if !vis[i] {
			current[depth] = nums[i]
			vis[i] = true
			recursive(nums, depth+1)
			vis[i] = false
		}
	}

}
