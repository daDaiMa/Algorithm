class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,bool>m;
        for(int n:nums){
            m[n]=true;
        }
        int ans=1;
        while(1){
           if(m[ans])ans++;
           else return ans;
        }
    }
};
