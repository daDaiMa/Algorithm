
func titleToNumber(s string) int {
	ans := 0
	//shit := 'A'
	//a := uint8('A')
	for i := 0; i < len(s); i++ {
		ans = ans*26 + int(s[i]-'A') + 1
	}
	return ans
}
