
func merge(nums1 []int, m int, nums2 []int, n int) {
	tmp := make([]int, m)
	copy(tmp, nums1)

	i := 0
	j := 0

	count := 0

	for i < m && j < n {
		if tmp[i] < nums2[j] {
			nums1[count] = tmp[i]
			i++
		} else {
			nums1[count] = nums2[j]
			j++
		}
		count++
	}
	
	for i<m{
		nums1[count]=tmp[i]
		count++
		i++
	}
	
	for j<n{
		nums1[count]=nums2[j]
		count++
		j++
	}
	
	return 
}
