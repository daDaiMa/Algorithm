class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())return 0;
        int ans=0;
        int has=-prices[0];
        int none=0;
        for(int i=1;i<prices.size();i++){
            int pre_none=none;
            none=max(has+prices[i],none);
            has=max(pre_none-prices[i],has);
            ans=max(ans,none);
        }
        return ans;
    }
};

