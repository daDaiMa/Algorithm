


const INT_MAX = int(^uint(0) >> 1)
const INT_MIN = ^INT_MAX

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	total := len(nums1) + len(nums2)
	long := nums1
	short := nums2
	if len(nums2) > len(nums1) {
		long = nums2
		short = nums1
	}

	start := 0
	end := len(short)
	var long_max_left int
	var short_max_left int
	var long_min_right int
	var short_min_right int

	for start <= end {

		partition_short := (start + end) / 2
		partition_long := (total+1)/2 - partition_short

		if partition_short == 0 {
			short_max_left = INT_MIN
		} else {
			short_max_left = short[partition_short-1]
		}
		if partition_long == 0 {
			long_max_left = INT_MIN
		} else {
			long_max_left = long[partition_long-1]
		}
		if partition_short == len(short) {
			short_min_right = INT_MAX
		} else {
			short_min_right = short[partition_short]
		}
		if partition_long == len(long) {
			long_min_right = INT_MAX
		} else {
			long_min_right = long[partition_long]
		}

		if short_min_right >= long_max_left && long_min_right >= short_max_left {
			if total%2 == 0 {
				return float64(max(short_max_left, long_max_left)+min(short_min_right, long_min_right)) / 2
			} else {
				return float64(max(short_max_left, long_max_left))
			}
		} else if short_max_left > long_min_right {
			end = partition_short - 1
		} else {
			start = partition_short + 1
		}

	}

	return 0
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
