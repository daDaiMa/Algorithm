
type NyString []string
func largestNumber(nums []int) string {
	sum := 0
	strs := make([]string, len(nums))
	for i := 0; i < len(nums); i++ {
		strs[i] = strconv.Itoa(nums[i])
		sum += nums[i]
	}
	if sum == 0 {
		return "0"
	}
	//strs =
	sort.Sort(NyString(strs))
	//fmt.Println(strs)
	var buffer bytes.Buffer

	for i := len(strs) - 1; i >= 0; i-- {
		buffer.WriteString(strs[i])
		//fmt.Println(buffer.String())
	}

	return buffer.String()
}

func (s NyString) Len() int {
	return len(s)
}
func (s NyString) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}
func (s NyString) Less(i, j int) bool {
	if len(s[i]) == len(s[j]) {
		return s[i] < s[j]
	}
	ii := 0
	ji := 0

	for {
		if ii == len(s[i]) || ji == len(s[j]) {
			return s[i]+s[j]<s[j]+s[i]
		}
		
		if s[i][ii] < s[j][ji] {
			return true
		} else if s[i][ii] == s[j][ji] {
			ii++
			ji++
		} else {
			return false
		}
	}
}
