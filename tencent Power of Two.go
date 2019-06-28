
func isPowerOfTwo(n int) bool {

    if n==0{
        return false
    }
    
	if n==1{
		return true
	}
	
	if n%2 != 0 {
		return false
	}

	for {
        
		if n==1||n==2{
			return true
		}
        
        if n%2!=0{
			return false
		}
        
		n/=2
	}
    
    return true
}
