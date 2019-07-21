
var ans [][]int
var max_deep int
//var cur_deep int
var current_array []int
var ans_num int

func subsets(nums []int) [][]int {
	if len(nums) == 0 {
		return [][]int{}
	}
	max_deep = len(nums)
	ans_num = 0
	current_array = make([]int, len(nums))
	ans = make([][]int, 1<<uint(len(nums)))
	//ans = make([][]int, 0)
	find_set(nums, 0, 0)

	return ans
}

func find_set(nums []int, d int, size int) {
	if d == max_deep {
		// fmt.Println(current_array[:size])
		//ans= append(ans,current_array[:size])
		ans[ans_num] = make([]int, size)
		//copy(ans[nums])
		copy(ans[ans_num], current_array[:size])
		// fmt.Println(ans)
		//ans[ans_num] = current_array[:size]
		ans_num++
		return
	}
	current_array[size] = nums[d]
	find_set(nums, d+1, size+1)
	find_set(nums, d+1, size)
}
