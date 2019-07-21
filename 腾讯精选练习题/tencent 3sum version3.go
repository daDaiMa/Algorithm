


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

	//tuple_set := make(map[[3]int]bool)
	tuple_set := make(map[string]bool)

	for first := 0; nums[first] <= 0 && first < len(nums)-2; first++ {
		second := first + 1
		third := len(nums) - 1

		for ; second < third; {
			if nums[first]+nums[second]+nums[third] == 0 {
				//may := [3]int{nums[first], nums[second], nums[third]}
				var buffer bytes.Buffer
				buffer.WriteString(strconv.Itoa(nums[first]))
				buffer.WriteByte('-')
				buffer.WriteString(strconv.Itoa(nums[second]))
				buffer.WriteByte('-')
				buffer.WriteString(strconv.Itoa(nums[third]))
				//buffer.WriteByte('-')

				may := buffer.String()
				if ok, _ := tuple_set[may]; !ok {
					tuple_set[may] = true
					result = append(result, []int{nums[first], nums[second], nums[third]})
				}
				second++
				third--
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

