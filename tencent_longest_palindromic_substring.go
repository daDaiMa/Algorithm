
func longestPalindrome(s string) string {
	size := len(s)

	if size <= 1 {
		return s
	}

	dp := make([][]bool, size)

	i := 0
	j := 0

	for ; j < size; j++ {
		dp[j] = make([]bool, size)
		dp[j][j] = true
	}

	begin_ptr := 0
	end_ptr := 1

	for i = 1; i < size; i++ {
		if s[i] == s[i-1] {
			dp[i-1][i] = true
			begin_ptr = i - 1
			end_ptr = i + 1
		}
	}

	j = 0


	for cur_max := 3; cur_max <= size; cur_max++ { //枚举子串最大长度
		for i = 0; i <= size-cur_max; i++ { //枚举开始下标
			j = i + cur_max - 1
			if s[i] == s[j] && dp[i+1][j-1] == true {
				begin_ptr = i
				end_ptr = j + 1
				dp[i][j] = true
			}
		}
	}

	return s[begin_ptr:end_ptr]
}
