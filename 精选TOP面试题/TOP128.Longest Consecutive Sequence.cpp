class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int ans=1,cur=1;
        for(int i=1;i<nums.size();i++){
           if(nums[i]-nums[i-1]==1){
               cur++;
               ans=max(ans,cur);
           }else if(nums[i]==nums[i-1]){
               continue;
           }else{
                cur=1;
           }
        }
        return ans;
    }
};

