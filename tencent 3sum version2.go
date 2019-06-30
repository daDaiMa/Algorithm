

func threeSum(nums []int) [][]int {

	if len(nums) < 3 {
		return [][]int{}
	}

	result := [][]int{}

	//先排序
	sort.Ints(nums)

	if nums[len(nums)-1] < 0 || nums[0] > 0 {
		return [][]int{}
	}

	tuple_set := make(map[[3]int]bool)

	for first := 0; nums[first] <= 0&& first < len(nums)-1; first++ {
		second := first + 1
		third := len(nums) - 1

		for ; second < third; {
			if nums[first]+nums[second]+nums[third] == 0 {
				may := [3]int{nums[first], nums[second], nums[third]}
				if ok, _ := tuple_set[may]; !ok {
					tuple_set[may] = true
					result = append(result, []int{may[0], may[1], may[2]})
				}
                third--
                second++
			} else {
				if nums[first]+nums[second]+nums[third] < 0 {
					second++
				} else {
					third--
				}
			}
		}

	}
	

	return result

}
