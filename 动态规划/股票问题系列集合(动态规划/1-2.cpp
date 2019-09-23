class Solution {
public:
    int maxProfit(vector<int>& prices) {
        buy=-prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
            sell=buy+prices[i];
            ans=max(ans,sell);
            buy=max(0-prices[i],buy);
        }
        return ans;
    }
};
