package main

import "fmt"

func main() {
	fmt.Println("vim-go")
}

func wiggleMaxLength(nums []int) int {
	if len(nums) <= 1 {
		return len(nums)
	}

	ans := 1
	pos := make([]int, len(nums))
	neg := make([]int, len(nums))

	pos[0] = 1
	neg[0] = -1

	for i := 1; i < len(nums); i++ {
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] {
				pos[i] = max(pos[i], -neg[j]+1)
			} else if nums[i] < nums[j] {
				neg[i] = -max(-neg[i], pos[j]+1)
			} else {
				pos[i] = 1
				neg[i] = -1
			}
			ans = max(pos[i], ans)
			ans = max(-neg[i], ans)
		}
	}

	return ans

}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
