class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int s=0,e=k-1;
        vector<int>ans;
        if(k==0||nums.size()==0)return ans;
        int _max=getMax(s,e,nums);
        ans.push_back(_max);
        for(++e;e<nums.size();e++){
            // 看看加进来的这个有没有比_max大
            if(nums[e]>_max)_max=nums[e];
            else{
                // 看看减少的是不是_max
                if(_max==nums[s]){
                    _max=getMax(s+1,e,nums);
                }
            }
            s++;
            ans.push_back(_max);
        }
        return ans;
    }
    int getMax(int s,int e,vector<int>&nums){
        int _max=nums[s];
        for(int i=s+1;i<=e;i++)
            _max=max(_max,nums[i]);
        return _max; 
    }
};

