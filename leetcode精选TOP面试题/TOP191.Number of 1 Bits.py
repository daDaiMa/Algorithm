class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans=0
        while n:
            ans+=n&1
            n>>=1
        return ans
    
# py骚操作
# return bin(n).count('1')
