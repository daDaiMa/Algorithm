
func increasingTriplet(nums []int) bool {
	if len(nums) < 3 {
		return false
	}
	min := nums[0]
	var mid int
	i := 1
	for ; i < len(nums); i++ {
		if nums[i] > min {
			mid = nums[i]
			break
		} else {
			min = nums[i]
		}
	}
	if i == len(nums) {
		return false
	}
	for ; i < len(nums); i++ {
		if nums[i] > mid {
			return true
		} else {
			if nums[i] > min {
				mid = nums[i]
			} else {
				min = nums[i]
			}
		}
	}
	return false
}
