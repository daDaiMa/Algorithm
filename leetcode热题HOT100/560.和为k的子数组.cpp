
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int*sum=new int[nums.size()];
        int ans=0;
        sum[0]=nums[0];
        for(int i=1;i<nums.size();i++)sum[i]=sum[i-1]+nums[i];
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if(sum[j]-sum[i]+nums[i]==k)ans++;
            }
        }
        return ans;
    }
};
