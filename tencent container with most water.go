

func maxArea(height []int) int {
	b:=0
	e:=len(height)-1
	max:=(e-b)*min(height[b],height[e])

	for b<e {
		m:=min(height[b],height[e])
		if max<m*(e-b){
			max=m*(e-b)
		}
		if height[b]==m{
			b++
		}else{
			e--
		}
	}

	return max
}

func min(a,b int)int{
	if a>b{
		return b
	}
	return a
}
