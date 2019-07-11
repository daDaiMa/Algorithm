
var ans []string
//var m map[string]bool

func generateParenthesis(n int) []string {
	//m = make(map[string]bool)
	ans = make([]string, 0)
	recursive("", 0, 0, n)
	return ans
}

func recursive(str string, l, r, n int) {
	if r > l || r > n || l > n {
		return
	}
	if l == n && r == n {
		ans = append(ans, str)
	}
	recursive(str+"(", l+1, r, n)
	recursive(str+")", l, r+1, n)
}
