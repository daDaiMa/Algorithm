
func productExceptSelf(nums []int) []int {
	out:=make([]int,len(nums))
	left:=make([]int,len(nums)+1)
	right:=make([]int,len(nums)+1)

	left[0]=nums[0]
	right[len(nums)-1]=nums[len(nums)-1]

	for i:=1;i<len(nums);i++{
		left[i]=left[i-1]*nums[i]
	}
	for j:=len(nums)-2;j>=0;j--{
		right[j]=right[j+1]*nums[j]
	}

	out[0]=right[1]
	out[len(nums)-1]=left[len(nums)-2]

	for i:=1;i<len(nums)-1;i++{
		out[i]=left[i-1]*right[i+1]
	}

	return out
}
