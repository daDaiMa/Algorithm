class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        for(int i=1;j<prices.size();i++){
            ans=max(0,ans+prices[i]-prices[i-1]);
        }
        return ans;
    }
};

