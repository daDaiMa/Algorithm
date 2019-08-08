
func myPow(x float64, n int) float64 {
	if n > 0 {
		return fastPow(x, n)
	}
	return fastPow(1/x, -n)
}

func fastPow(x float64, n int) float64 {
	if n == 0 {
		return 1.0
	}
	half := fastPow(x, n/2)
	if n%2 == 0 {
		return half * half
	}
	return half * half * x
}
