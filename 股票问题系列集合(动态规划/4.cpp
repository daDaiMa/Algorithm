// 太菜了 折腾了3小时 终于好了
class Solution{
    public:
        int maxProfit(int k, vector<int>& prices) {
            if(!prices.size()||!k)return 0;
            if(k>prices.size()/2){
                cout<<"shit";
                return maxProfitUtil(prices);
            }
            // 恒等式dp[i][2]=0;
            vector<vector<int>>dp(k+1,vector<int>(2,0));
            int ans=0;
            for(int i=0;i<k;i++)dp[i][1]=-prices[0];
            for(int i=1;i<prices.size();i++){
                for(int j=k-1;j>=0;j--){        
                    dp[j][0]=max(dp[j][1]+prices[i],dp[j][0]);
                    dp[j][1]=max(dp[j+1][0]-prices[i],dp[j][1]);
                    ans=max(ans,dp[j][0]);
                }
            }
            return ans;
        }
        int maxProfitUtil(vector<int>& prices) {
            if(!prices.size())return 0;
            int ans=0;
            vector<vector<int>>dp(prices.size(),vector<int>(2,0));
            dp[0][0]=0;
            dp[0][1]=-prices[0];
            for(int i=1;i<prices.size();i++){
                dp[i][0]=max(dp[i-1][1]+prices[i],dp[i-1][0]);
                dp[i][1]=max(dp[i-1][0]-prices[i],dp[i-1][1]);
                ans=max(ans,dp[i][0]);
            }
            return ans;
        }
};
