
func multiply(num1 string, num2 string) string {

	if num1 == "0" || num2 == "0" {
		return "0"
	}
	if num1 == "1" {
		return num2
	}
	if num2 == "1" {
		return num1
	}

	var short string
	var long string

	if len(num1) > len(num2) {
		long = num1
		short = num2
	} else {
		long = num2
		short = num1
	}

	zero_num := 0

	var buffer bytes.Buffer
	var tmp uint8
	var c uint8 = 0

	ans := "0"

	for i := len(short) - 1; i >= 0; i-- {
		buffer.Reset()
		c = 0

		for z := 0; z < zero_num; z++ {
			buffer.WriteByte('0')
		}

		if short[i] == '0' {
			zero_num++
			continue
		}

		if short[i] == '1' {
			for index := len(long) - 1; index >= 0; index-- {
				buffer.WriteByte(long[index])
			}
			zero_num++
			ans = add(ans, buffer.String())
			continue
		}

		for j := len(long) - 1; j >= 0; j-- {
			tmp = (short[i]-'0')*(long[j]-'0') + c
			c = 0
			if tmp > 9 {
				c = tmp / 10
				tmp %= 10
			}
			buffer.WriteByte(tmp + '0')
		}
		if c > 0 {
			buffer.WriteByte(c + '0')
			c = 0
		}

		zero_num++
		ans = add(ans, buffer.String())
	}

	buffer.Reset()

	for i := len(ans) - 1; i >= 0; i-- {
		buffer.WriteByte(ans[i])
	}

	return buffer.String()
}

func add(num1 string, num2 string) string {

	if num1 == "0" {
		return num2
	}
	if num2 == "0" {
		return num1
	}

	var buffer bytes.Buffer
	var tmp uint8
	var c uint8 = 0

	i := 0

	for i = 0; i < len(num1) && i < len(num2); i++ {
		tmp = (num1[i] - '0') + (num2[i] - '0') + c
		c = 0
		if tmp > 9 {
			tmp %= 10
			c = 1
		}
		buffer.WriteByte(tmp + '0')
	}

	for ; i < len(num1); i++ {
		tmp = num1[i] - '0' + c
		c = 0
		if tmp > 9 {
			tmp %= 10
			c = 1
		}
		buffer.WriteByte(tmp + '0')
	}

	for ; i < len(num2); i++ {
		tmp = num2[i] - '0' + c
		c = 0
		if tmp > 9 {
			tmp %= 10
			c = 1
		}
		buffer.WriteByte(tmp + '0')
	}

	if c > 0 {
		buffer.WriteByte('1')
	}

	return buffer.String()
}
