
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len=nums.size();
        int Max,MAX;
        for(Max=0;Max<len-1&&nums[Max]<=nums[Max+1];Max++);
        if(Max==len-1)return 0;
        for(MAX=len-1;MAX>0&&nums[MAX]>=nums[MAX-1];MAX--);
        if(MAX==0)return 0;
    
        int m_min=Max;
        int m_max=MAX;
        
        
        for(int i=Max;i<=MAX;i++){
            if(nums[i]<nums[m_min])m_min=i;
            if(nums[i]>nums[m_max])m_max=i;
        } 
        

        while(Max>=0&&nums[Max]>nums[m_min])Max--;
        while(MAX<len&&nums[MAX]<nums[m_max])MAX++;
        
        return len-(Max+1)-(len-MAX);
    }
};

