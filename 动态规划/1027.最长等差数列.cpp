class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        if(A.size()<=2){
            return A.size();
        }
        int ans=1;
        vector<vector<int>>dp(A.size(),vector<int>(20001,1));
        for(int i=1;i<A.size();i++){
            for(int j=0;j<i;j++){
                // 为啥+10000 因为等差可以是负数 这样数组访问就出问题了
                // 所以加10000转换一下 当然是看了别人的做法Orz
                int sub=A[i]-A[j]+10000;
                dp[i][sub]=max(dp[i][sub],dp[j][sub]+1);
                ans=max(dp[i][sub],ans);
            }
        }
        return ans;
    }
};

