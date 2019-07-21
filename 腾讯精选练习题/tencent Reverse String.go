
func reverseString(s []byte)  {
    i:=0
    j:=len(s)-1
    
    var tmp byte
    for ;i<=j;{
        tmp = s[i]
        s[i] = s[j]
        s[j] = tmp
        i++
        j--
    }
}
