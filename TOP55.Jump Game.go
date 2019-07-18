
func canJump(nums []int) bool {
	dp := make([]bool, len(nums))
	for i := 0; i < len(nums); i++ {
		dp[i] = false
	}
	dp[0] = true
	for i := 0; i < len(nums); i++ {
		if dp[i] {
			for j := 1; i+j < len(nums)&&j<=nums[i]; j++ {
				dp[i+j] = true
			}
		}
	}
	return dp[len(nums)-1]
}
