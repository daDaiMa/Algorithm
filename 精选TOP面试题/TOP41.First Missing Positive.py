class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        ans=1
        for i in range(len(nums)):
            if ans in nums:
                ans+=1
        return ans
