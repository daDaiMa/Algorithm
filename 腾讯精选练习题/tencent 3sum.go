

func threeSum(nums []int) [][]int {

	if len(nums) < 3 {
		return [][]int{}
	}

	result := [][]int{}
	ori_map := make(map[int]int)

	for i := 0; i < len(nums); i++ {
		ori_map[nums[i]] = i
	}

	tuple_set := make(map[[3]int]bool)

	for i := 0; i < len(nums)-2; i++ {
		for j := i + 1; j < len(nums)-1; j++ {

			if v, ok := ori_map[-(nums[i] + nums[j])]; ok && v > j {
				tmp := []int{nums[i], nums[j], nums[v]}
				sort.Ints(tmp)
				may := [3]int{tmp[0], tmp[1], tmp[2]}
				if ok, _ := tuple_set[may]; !ok {
					tuple_set[may] = true
					result = append(result, []int{may[0], may[1], may[2]})
				}
			}
		}
	}

	return result

}
