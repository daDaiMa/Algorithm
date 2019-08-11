
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> ans(2);
        auto upper = upper_bound(nums.begin(), nums.end(), target);
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        if (lower == nums.end()) {ans[0]=ans[1]=-1;return ans;}
        if(*lower!=target){ans[0]=ans[1]=-1;return ans;}
        ans[0]=lower-nums.begin();
        upper--;
        if(*upper!=target){
            ans[0]=ans[1]=-1;
            return ans;
        }else{
            ans[1]=upper-nums.begin();
        }
        return ans;
    }
};
