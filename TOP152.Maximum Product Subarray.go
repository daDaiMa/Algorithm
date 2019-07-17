/*
   有点小技巧 看了题解才知道 暴力法没啥意思
   维护一个最大值和最小值 
*/
func maxProduct(nums []int) int {
	tmax := 1
	tmin := 1
	max := math.MinInt32
	for _, v := range nums {
		if v < 0 {
			tmax += tmin
			tmin = tmax - tmin
			tmax -= tmin
		}
		tmin = int(math.Min(float64(v), float64(tmin*v)))
		tmax = int(math.Max(float64(tmax*v), float64(v)))
		max = int(math.Max(float64(tmax), float64(max)))
	}
	return max
}
