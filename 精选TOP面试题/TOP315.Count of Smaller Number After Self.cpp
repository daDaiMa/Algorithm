class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int num=0;
            for(int j=i+1;j<nums.size();j++){
               if(nums[i]>nums[j])num++; 
            }
            ans.push_back(num);
        }
        return ans;
    }
};
