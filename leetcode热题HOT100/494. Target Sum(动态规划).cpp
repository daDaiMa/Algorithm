/*
 * 大佬的方法(偷😂
 * 令P  Q为nums的子集
 * P+Q=nums
 * 如果sum(P)-sum(Q)=S
 * sum(P)+sum(Q)+sum(P)-sum(Q)=S+sum(P)+sum(Q);
 * 2*sum(P)=S+sum(P)+sum(Q);
 * 2*sum(P)=S+sum(nums);
 * sum(P)=(S+sum(nums))/2;
 * 问题转化成求P集合可能的数量
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum_nums=0;
        for(auto num:nums)sum_nums+=num;
        if(sum_nums<S||(sum_nums+S)%2!=0)return 0;
        int sum_p=(S+sum_nums)/2;

        vector<int>dp(sum_p+1,0);
        dp[0]=1; 
        for(auto num:nums)
            for(int i=sum_p;i>=num;i--)
                dp[i]+=dp[i-num];

        return dp[sum_p];

    }
};

