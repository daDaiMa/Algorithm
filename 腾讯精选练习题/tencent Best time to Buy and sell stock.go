
func maxProfit(prices []int) int {
    
    if len(prices)==0{
        return 0
    }
    
	b := 0
	e := len(prices) - 1

	min := prices[b]
	max := prices[e]

	result := 0

	for b <= e {
		if prices[b] < min {
			min = prices[b]
			
		} else {
			if prices[b] > max && prices[b]-min>result {
				result = prices[b]-min
			}
		}

		if prices[e] > max {
			max = prices[e]
			
		} else {
			if prices[e] < min && max-prices[e]>result {
				result =max-prices[e]
			}
		}
		b++
		e--
	}
	
	
	
	if max-min<result{
		return result
	}
	
	return max - min
}

