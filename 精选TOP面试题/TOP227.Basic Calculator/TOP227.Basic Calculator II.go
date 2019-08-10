
var str string
var index int

func calculate(s string) int {
	str = s
	index = 0
	return getExpresionValue()
}

func getExpresionValue() int {
	itemA := getItemValue()
	for {
		if index >= len(str) {
			break
		}
		getRidOfSpan()
		op := str[index]
		if op == '-' {
			index++
			itemA -= getItemValue()
		} else if op == '+' {
			index++
			itemA += getItemValue()
		}
	}
	return itemA
}

func getItemValue() int {
	factorA := getFactorValue()
	for {
		if index >= len(str) {
			break
		}
		getRidOfSpan()
		op := str[index]
		if op == '/' {
			index++
			factorA /= getFactorValue()
		} else if op == '*' {
			index++
			factorA *= getFactorValue()
		} else {
			break
		}
	}
	return factorA
}

func getFactorValue() int {
	val := 0
	for {
		if index >= len(str) {
			break
		}
		if str[index] == ' ' {
			index++
			continue
		}
		if isDigit(str[index]) {
			val = val*10 + int(str[index]-'0')
			index++
		} else {
			break
		}
	}
	return val
}

func isDigit(c byte) bool {
	return c >= '0' && c <= '9'
}

func getRidOfSpan() {
	for {
		if index >= len(str) {
			break
		}
		if str[index] == ' ' {
			index++
		} else {
			break
		}
	}
}
