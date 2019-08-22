class Solution{
    public:
    int maxProfit(vector<int>&prices){
        if(!prices.size())return 0;
        // 恒等式dp[i][2]=0;
        vector<vector<int>>dp(3,vector<int>(2,0));
        int ans=0;
        dp[2][0]=0;
        dp[1][1]=-prices[0];
        dp[0][1]=-prices[0];  
        for(int i=1;i<prices.size();i++){
            for(int j=1;j>=0;j--){
                dp[j][0]=max(dp[j][1]+prices[i],dp[j][0]);
                dp[j][1]=max(dp[j+1][0]-prices[i],dp[j][1]);
                ans=max(ans,dp[j][0]);
            }
        }
        return ans;
    }
};

