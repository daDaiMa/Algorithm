
func uniquePaths(m int, n int) int {
	dp := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int, m+1)
	}

	dp[1][1] = 1

	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if i == 1 && j == 1 {
				continue
			}
			dp[i][j] = dp[i-1][j] + dp[i][j-1]
		}
	}
	
	return dp[n][m]
}
