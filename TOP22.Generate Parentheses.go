
func generateParenthesis(n int) []string {
	ans := make([]string, 0)
	for i := MIN(n); i <= MAX(n); i++ {
		if ok, str := Check(n*2, i); ok {
			//reversal(str)
			ans = append(ans, string(str))
		}
	}
	return ans
}

func MAX(n int) int {
	return 1<<uint(2*n) - 1<<uint(n)
}

func MIN(n int) int {
	min := 0
	for i := 0; i < n*2; i += 2 {
		min += 1 << uint(i+1)
	}
	return min
}

func Check(size, n int) (bool, []byte) {
	var buffer bytes.Buffer
	weight := 0
	base := 1 << uint(size-1)
	for {
		if n&base == base {
			weight += 1
			buffer.WriteByte('(')
		} else {
			weight -= 1
			buffer.WriteByte(')')
			if weight < 0 {
				return false, []byte{}
			}
		}
		n <<= 1
		size--
		if size == 0 {
			return weight == 0, buffer.Bytes()
		}
	}
}
