

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=1;
        for(;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                return nums[i];
            }
        }
    }
};
