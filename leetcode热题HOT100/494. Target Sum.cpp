class Solution {
public:
    int ps[21];
    int ans, cur ,size ,sum;
    int findTargetSumWays(vector<int>& nums, int S) {
        ps[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            ps[i]=ps[i-1]+nums[i];
        }
        sum=S;
        size=nums.size();
        cur=0;
        ans=0;
        dfs(0,nums);  
        return ans;
    }

    void dfs(int d,vector<int>&nums){
        if(d==size){
            if(cur==sum)ans+=1;
            return;
        } 
        
        if(abs(sum-cur)>abs(ps[size-1]-ps[d]+nums[d]))return;
            
        int temp=cur;
        cur+=nums[d];
        dfs(d+1,nums);
        cur=temp-nums[d];
        dfs(d+1,nums);
    }
};

