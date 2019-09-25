#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i=1;i<=word1.size();i++)dp[i][0]=dp[i-1][0]+1;
        for(int i=1;i<=word2.size();i++)dp[0][i]=dp[0][i-1]+1;
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){
                    // 相同的话 需要修改的数量和 i-1 j-1一样
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    //i-1 j-1 表示替换 i j替换成一样的就行了
                    //i-1 j 表示删除   
                    //i j-1 表示插入 在原来的i-1 j-1的基础上 i变多了1 所以看作插入
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }
        }
        return dp.back().back();
    }
};
