//这个题目有点恶心
//方法如下
//首先一分为二数组，肯定有一半是有序的
//然后呢 怎么判断哪一半是有序的 哪一半是无序的呢
//如果 mid 对应的值比两边大或者比两边小 那肯定不是有序的（看代码38
//如果是有序的 只要进行 二分就行了 否则 进行deep_search
func search(nums []int, target int) int {
    if len(nums)==0{
        return -1
    }
	return binary_search(0, len(nums)-1, nums, target)
}

func binary_search(b int, e int, nums []int, target int) int {

	if b == e {
		if nums[b] == target {
			return b
		}
		return -1
	}

	if e-b == 1 {
		if nums[b] == target {
			return b
		}
		if nums[e] == target {
			return e
		}
		return -1
	}

	ori_b := b
	ori_e := e

	deep_search := false
	mid := (b + e) / 2

	if nums[mid] < nums[ori_b] && nums[mid] < nums[ori_e] {
		deep_search = true
	}
	if nums[mid] > nums[ori_b] && nums[mid] > nums[ori_e] {
		deep_search = true
	}

	if deep_search {

		mid = (ori_b + ori_e) / 2

		ans := binary_search(ori_b, mid, nums, target)

		if ans != -1 {
			return ans
		}

		ans = binary_search(mid+1, ori_e, nums, target)

		return ans
	}

	for b <= e {
		mid := (b + e) / 2
		if nums[mid] == target {
			return mid
		}
		if nums[mid] < target {
			b = mid + 1
		} else {
			e = mid - 1
		}
	}

	return -1
}
