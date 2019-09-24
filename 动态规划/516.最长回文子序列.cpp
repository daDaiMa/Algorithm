#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),0));

        int len=s.length();

        for(int i=0;i<len;i++) dp[i][i]=1;

        int ans=1;
        for(int i=len-1;i>=0;i--){
            for(int j=i+1;j<len;j++){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
                }
                ans=max(ans,dp[i][j]);
            }
        }
                
        return ans;

    }
};

