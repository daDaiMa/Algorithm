




func majorityElement(nums []int) int {
	sort.Ints(nums)

	count := 1

	for i := 1; i < len(nums); i++ {
		if nums[i] == nums[i-1] {
			count++
			if count > len(nums)/2 {
				return nums[i]
			}
		} else {
			count = 1
		}
	}
	
	return nums[0]
}

