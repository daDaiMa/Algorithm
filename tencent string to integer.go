

func myAtoi(str string) int {
	if len(str) == 0 {
		return 0
	}
	start := 0
	sign := 1
	for ; start < len(str); {
		if str[start] == '-' || str[start] == '+' {
			if str[start] == '-' {
				sign = -1
			}
			start++
			break
		}
		if str[start] == ' ' {
			start++
			continue
		}
		if str[start] > '9' || str[start] < '0' {
			return 0
		} else {
			break
		}
	}

	num := 0

	for i := start; i < len(str); i++ {
		if str[i] > '9' || str[i] < '0' {
			break
		} else {
			num = num*10 + int(str[i]-'0')
			if num > 2147483648 {
				break
			}
		}
	}

	num *= sign

	if num < -2147483648 {
		return -2147483648
	}

	if num > 2147483647 {
		return 2147483647
	}

	return num
}

