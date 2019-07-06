
func climbStairs(n int) int {

	if n==1{
		return 1
	}
	if n==2{
		return 2
	}
	
	a:=1
	b:=2
	var c int
	for i:=3;i<=n;i++{
		c=a+b
		a=b
		b=c
	}
	return c
}

