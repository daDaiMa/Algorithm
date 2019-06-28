func strStr(haystack string, needle string) int {

	if len(needle) == 0 {
		return 0
	}

	kmp := make([]int, len(needle)+1)

	i := 0
	j := 1

	//a a c b f a a b a a a  c  b  d  d
	//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14

	for ; j < len(needle); {
		if needle[i] == needle[j] {
			kmp[j] = i + 1
			i++
			j++
		} else {
			if i == 0 {
				kmp[j] = 0
				j++
			} else {
				i = kmp[i-1]
			}
		}
	}

	//for _, v := range needle {
	//	fmt.Printf("%c\t", v)
	//}
	//
	//fmt.Println()
	//
	//for i, _ := range needle {
	//	fmt.Printf("%d\t", kmp[i])
	//}

	ok := true
	j = 0
	for i = 0; i < len(haystack); {
		if j < len(needle) {
			if haystack[i] == needle[j] {
				i++
				j++
				ok = true
			} else {
				if j == 0 {
					i++
				} else {
					j = kmp[j-1]
				}
				ok = false
			}
		} else {
			return i - len(needle)
		}
	}

	if j == len(needle) && ok {
		return i - len(needle)
	}

	return -1
}
