
func fractionToDecimal(numerator int, denominator int) string {
	if numerator%denominator == 0 {
		return strconv.Itoa(numerator / denominator)
	}
	m := make(map[int]int)
	ans := calculateInteger(numerator, denominator)
    numerator=abs(numerator)
    denominator=abs(denominator)
	numerator %= denominator
	numerator *= 10
	var buffer bytes.Buffer
	count := 0
	for {
		if v, ok := m[numerator]; ok {
			tmp := buffer.String()
			ans += tmp[:v]
			ans += "(" + tmp[v:count] + ")"
			return ans
		}
		buffer.WriteByte(byte(numerator/denominator + '0'))
		m[numerator] = count
		count++
		numerator = (numerator % denominator) * 10
		if numerator == 0 {
			return ans + buffer.String()
		}
	}
}

func calculateInteger(a, b int) string {
    ans:=strconv.Itoa(a/b) + "."
    if a*b<0&&a/b==0{
        ans="-"+ans
    }
    return ans
}

func abs(a int)int{
	if a>0{
		return a
	}
	return -1*a
}
