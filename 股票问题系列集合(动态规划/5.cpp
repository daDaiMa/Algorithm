class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())return 0;
        int s[3]={ 0,-prices[0],0 };
        int ans=0;
        for(int i=1;i<prices.size();i++){
            int ori_s2=s[2];
            s[2]=s[1]+prices[i];
            s[1]=max(s[1],s[0]-prices[i]);
            s[0]=max(s[0],ori_s2);
            ans=max(ans,s[2]);
            ans=max(ans,s[0]);
        }
        return ans;
    }
};
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        if(!prices.size())return 0;
//        vector<vector<int>>dp(prices.size()+1,vector<int>(3,0));
//        dp[0][1]=-prices[0];
//        int ans=0;
//        for(int i=1;i<prices.size();i++){
//            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);  
//            dp[i][0]=max(dp[i-1][0],dp[i-1][2]);
//            dp[i][2]=dp[i-1][1]+prices[i];
//            ans=max(ans,dp[i][2]);
//            ans=max(ans,dp[i][0]);
//        }
//        return ans;
//    }
//};















