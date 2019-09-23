package main

func wiggleMaxLength(nums []int) int {
	if len(nums) < 2 {
		return len(nums)
	}

	up := 1
	down := 1

	ans := 1

	for i := 1; i < len(nums); i++ {
		if nums[i] > nums[i-1] {
			down = up + 1
		} else if nums[i] < nums[i-1] {
			up = down + 1
		}
		ans = max(ans, down)
		ans = max(ans, up)
	}

	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// O(n)空间复杂度
/*
package main

func wiggleMaxLength(nums []int) int {
	if len(nums) < 2 {
		return len(nums)
	}

	up := make([]int, len(nums))
	down := make([]int, len(nums))

	up[0] = 1
	down[0] = 1

	ans:=1

	for i := 1; i < len(nums); i++ {
		if nums[i] > nums[i-1] {
			up[i] = up[i-1]
			down[i] = up[i-1] + 1
		} else if nums[i] < nums[i-1] {
			up[i] = down[i-1] + 1
			down[i] = down[i-1]
		} else {
			down[i] = down[i-1]
			up[i] = up[i-1]
		}
		ans=max(ans,down[i])
		ans=max(ans,up[i])
	}

	return ans
}

func max(a,b int)int{
	if a>b{
		return a
	}
	return b
}
*/
