type NumArray struct {
	nums []int 
	sum []int
}


func Constructor(nums []int) NumArray {
	sum:=make([]int,len(nums))
	if len(nums)>0{
		sum[0]=nums[0]
	}
	
	for i:=1;i<len(nums);i++{
		sum[i]=sum[i-1]+nums[i]
	}

	return NumArray{nums,sum}
}


func (this *NumArray) SumRange(i int, j int) int {
	return this.sum[j]-this.sum[i]+this.nums[i] 
}


/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(i,j);
 */
