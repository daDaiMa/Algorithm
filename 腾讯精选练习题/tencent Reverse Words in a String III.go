
func reverseWords(s string) string {


	var buffer bytes.Buffer

	has_head := false

	word_head := 0
	for i := 0; i < len(s); i++ {
		if s[i] == '"' || s[i] == ' ' {

			for index := i - 1; index >= word_head; index-- {
				buffer.WriteByte(byte(s[index]))
			}

			buffer.WriteByte(byte(s[i]))
			has_head = false
			word_head = i

		} else {
			if !has_head {
				has_head = true
				word_head = i
			}
		}
	}

	for i := len(s) - 1; i >= word_head; i-- {
		buffer.WriteByte(byte(s[i]))
	}

	return buffer.String()
}

