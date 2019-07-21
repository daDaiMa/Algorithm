
func grayCode(n int) []int {
	ans := []int{}
	for i := 0; i < 1<<uint(n); i++ {
		ans = append(ans, i^(i>>1))
	}
	return ans
}
