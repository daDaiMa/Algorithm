
var ans []string
var m map[string]bool

func generateParenthesis(n int) []string {
	m = make(map[string]bool)
	recursive(n, "", "")
	return ans
}

func recursive(d int, pre, bck string) {
	if d == 0 {
		str := pre + bck
		if ok, _ := m[str]; !ok {
			ans = append(ans, pre+bck)
			m[str] = true
		}
		return
	}
	d--
	recursive(d, pre+"(", ")"+bck)
	recursive(d, pre+"()", bck)
	recursive(d, pre, "()"+bck)
}
