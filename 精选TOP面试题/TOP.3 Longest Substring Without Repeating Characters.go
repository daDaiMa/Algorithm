func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	b := 0
	e := 0

	set := make([]bool, 150)

	max := 1
	shorten := false
	set[s[b]] = true
	current := 1

	for {
		if shorten {
			set[s[b]] = false
			b++
			if b == e {
				set[s[e]] = true
				current = 1
				shorten = false
                continue
			}
			current--
			if !set[s[e]] {
				shorten = false
				set[s[e]] = true
				current++
			}
		} else {
			e++
			if e == len(s) {
				break
			}
			if set[s[e]] {
				shorten = true
				if current > max {
					max = current
				}
			} else {
				set[s[e]] = true
				current++
			}
		}
	}
    
    if current>max{
        return current
    }

	return max

}
