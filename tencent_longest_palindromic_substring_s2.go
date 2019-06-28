func longestPalindrome(s string) string {
	size := len(s)

	if size <= 1 {
		return s
	}

	max_size := 1

	b_ptr := 0
	e_ptr := 1

	for i := 1; i < len(s); i++ {
		if length := one_mid(&s, i); length > max_size {
			b_ptr = i - (length-1)/2
			e_ptr = i + (length+1)/2
			max_size = length
		}
		if s[i-1] == s[i] {
			if length := two_mid(&s, i-1, i); length > max_size {
				b_ptr = i - 1 - (length-2)/2
				e_ptr = i + (length-2)/2 + 1
				max_size = length
			}
		}
	}

	return s[b_ptr:e_ptr]
}

func one_mid(s *string, i int) int {
	length := 1
	j := i + 1
	i--
	for ; i >= 0 && j < len(*s); {
		if (*s)[i] == (*s)[j] {
			length += 2
			i--
			j++
		} else {
			break
		}
	}
	return length
}

func two_mid(s *string, i int, j int) int {
	length := 2
	i--
	j++
	for ; i >= 0 && j < len(*s); {
		if (*s)[i] == (*s)[j] {
			length += 2
			i--
			j++
		} else {
			break
		}
	}
	return length
}
