
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>tmp(nums.begin(),nums.end());
        int count=0;
        for(int a:tmp){
            if(a)nums[count++]=a;
        }
        while(count<nums.size()){
            nums[count++]=0;
        }
    }
};
