
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
    return s[i]+s[j]<s[j]+s[i]
}
