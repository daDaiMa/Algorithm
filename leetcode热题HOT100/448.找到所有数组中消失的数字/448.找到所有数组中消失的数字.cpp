class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len=nums.size();
        if(!len)return nums;
        for(int i=0;i<len;i++){
            cout<<nums[i]<<endl;
            int index=(nums[i]-1)%len;
            nums[index]+=len; 
        }
        vector<int>ans(0);
        for(int i=0;i<len;i++){
            if(nums[i]<=len)ans.push_back(i+1);
        }
        return ans;
    }
};

