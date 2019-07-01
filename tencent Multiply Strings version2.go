

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

	max_length := len(num1) + len(num2)
	ans := make([]uint8, max_length)
	var buffer bytes.Buffer
	for i := 0; i < max_length; i++ {
		//buffer.WriteByte('0')
		ans[i] = 0
	}
	//_, _ = buffer.Read(ans)

	num1_len := len(num1)
	num2_len := len(num2)

	var tmp uint8

	for i := 0; i < num1_len; i++ {
		for j := 0; j < num2_len; j++ {
			tmp = (num1[num1_len-i-1] - '0') * (num2[num2_len-j-1] - '0')
			ans[i+j] += tmp % 10
			if ans[i+j] > 9 {
				ans[i+j] %= 10
				ans[i+j+1] += 1
			}
			ans[i+j+1] += tmp / 10
			if ans[i+j+1] > 9 {
				ans[i+j+1] %= 10
				ans[i+j+2] += 1
			}
		}
	}

	max_length--
	for ; ans[max_length] == 0; max_length-- {

	}

	for ; max_length >= 0; max_length-- {
		buffer.WriteByte(ans[max_length] + '0')
	}

	return buffer.String()

	//for index:=max_length-1;

}
