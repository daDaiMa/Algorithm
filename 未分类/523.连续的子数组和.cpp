#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int>sum(nums.size(),0); 
        sum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            sum[i]=sum[i-1]+nums[i];
            if(!k&&nums[i]==0&&nums[i-1]==0)return true;
        }
        
        if(!k)return false;

        for(int i=0;i<nums.size();i++)
            for(int j=i+1;j<nums.size();j++){
                if((sum[j]-sum[i]+nums[i])%k==0)return true;
            }
        return false;
    }
};

