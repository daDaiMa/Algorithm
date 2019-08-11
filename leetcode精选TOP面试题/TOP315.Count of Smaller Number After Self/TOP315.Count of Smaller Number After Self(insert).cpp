class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size()==0)return vector<int>();
        vector<int>ans(nums.size(),0);        
        vector<int> sortedList;
        sortedList.push_back(nums.back());
        for(int i=nums.size()-2;i>=0;i--){
            auto it=upper_bound(sortedList.begin(),sortedList.end(),nums[i]);
            ans[i]=it-sortedList.begin();
            sortedList.insert(it,nums[i]);
        }
        return ans;
    }
};
