
func threeSumClosest(nums []int, target int) int {

	sort.Ints(nums)

	min := abs(nums[len(nums)-1] + nums[len(nums)-2] + nums[len(nums)-3] - target)
	ans := nums[len(nums)-1] + nums[len(nums)-2] + nums[len(nums)-3]

	for i := 0; i < len(nums); i++ {
		b := i + 1
		e := len(nums) - 1
		for b < e {
			if abs(nums[i]+nums[b]+nums[e]-target) < min {
				min = abs(nums[i] + nums[b] + nums[e] - target)
				ans = nums[i] + nums[b] + nums[e]
				if min == 0 {
					return target
				}
			}

			if nums[i]+nums[b]+nums[e] > target {
				e--
			} else {
				b++
			}

		}
	}

	return ans
}

func abs(a int) int {
	if a < 0 {
		return a * -1
	}
	return a
}
