
class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size())return 0;
        int ans=0;
        int front_2=0;
        int front_1=0;
        for(auto&x:nums){
           int cur=max(front_2+x,front_1);
           ans=max(ans,cur);
           front_2=front_1;
           front_1=cur;
        }
        return ans;
    }
};
