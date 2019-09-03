func maxSubArray(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	//dp := make([]int, len(nums))
	max := nums[0]

	sum := 0

	for i := 0; i < len(nums); i++ {
		sum += nums[i]
		if sum > max {
			max = sum
		}
		if sum < 0 {
			sum = 0
		}
	}

	return max
	//for i:=1;i<len(nums);i++{
	//if dp[i-1]+
	//}
}
