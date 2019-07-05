
func findKthLargest(nums []int, k int) int {
	//和快速排序差不多的道理
	quick_sort(0,len(nums),k,nums)
	return nums[len(nums)-k]
}

func quick_sort(b,e,k int,nums[]int){
	//左闭右开 
	if e-b<2{
		return
	}
	pivot:=nums[b]
	ptrb:=b
	ptre:=e-1

	for ptrb<ptre{
		for nums[ptre]>pivot&&ptrb<ptre{
			ptre--
		}
		for nums[ptrb]<=pivot&&ptrb<ptre{
			ptrb++
		}
		tmp:=nums[ptrb]
		nums[ptrb]=nums[ptre]
		nums[ptre]=tmp
	}	
	nums[b]=nums[ptrb]
	nums[ptrb]=pivot
	
	if len(nums)-k==ptrb{
		return 
	}

	if len(nums)-k>ptrb{
		quick_sort(ptrb+1,e,k,nums)
	}else{
		quick_sort(b,ptrb,k,nums)
	}

}
