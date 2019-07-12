
func divide(dividend int, divisor int) int {

	if dividend == -1*(1<<31) && divisor == -1 {
		return 1<<31 - 1
	}

	if dividend == 0 {
		return 0
	}

	sign := 1
	if dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0 {
		sign = -1
	}

	dividend = abs(dividend)
	divisor = abs(divisor)

	base := divisor
	count := 1
	ans := 0

	reverse := false

	for dividend >= divisor {
		if dividend >= base {
			dividend -= base
			ans += count
			if reverse {
				count >>= 1
				base >>= 1
			} else {
				base = base + base
				count = count + count
			}
		} else {
			reverse = true
			count >>= 1
			base >>= 1
		}
	}
	return ans * sign
}

func abs(a int) int {
	if a > 0 {
		return a
	}
	return -1 * a
}
