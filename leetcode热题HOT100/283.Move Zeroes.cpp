
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index=0;
        int next=0;
        while(next<nums.size()){
            if(nums[next])nums[index++]=nums[next];
            next++;
        }
        while(index<nums.size())nums[index++]=0;
    }
};
