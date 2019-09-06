
class Solution {
public:
    int BIG_INT=1<<30;
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(!matrix.size())return 0;
        vector<vector<vector<int>>>dp(matrix.size(),vector<vector<int>>(matrix[0].size(),vector<int>(2,0)));
        
        dp[0][0][1]=dp[0][0][0]=(matrix[0][0]=='1'?1:0);
        int ans=dp[0][0][0];
        for(int i=1;i<matrix.size();i++){
            if(matrix[i][0]=='1'){
                dp[i][0][0]=1;
                dp[i][0][1]=dp[i-1][0][1]+1;
                ans=max(ans,dp[i][0][1]);
            }
        }
        for(int i=1;i<matrix[0].size();i++){
            if(matrix[0][i]=='1'){
                dp[0][i][0]=dp[0][i-1][0]+1;
                dp[0][i][1]=1;
                ans=max(ans,dp[0][i][0]);
            }
        }

        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[i].size();j++){
                if(matrix[i][j]!='1')continue;
                if(matrix[i-1][j-1]!='1')dp[i-1][j-1][0]=dp[i-1][j-1][1]=BIG_INT;
                if(matrix[i-1][j]!='1')dp[i-1][j][1]=BIG_INT;
                if(matrix[i-1][j]!='1')dp[i][j-1][0]=BIG_INT;

                if(matrix[i-1][j-1]=='0'||
                        matrix[i-1][j]=='0'||
                        matrix[i][j-1]=='0'){
                    if(dp[i-1][j][1]>dp[i][j-1][0]){
                        dp[i][j][0]=1;
                        dp[i][j][1]=dp[i-1][j][1]+1;
                    }else{
                        dp[i][j][1]=1;
                        dp[i][j][0]=dp[i][j-1][0]+1;
                    }
                }else{
                    dp[i][j][0]=min(dp[i-1][j-1][0],dp[i][j-1][0])+1;
                    dp[i][j][1]=min(dp[i-1][j-1][1],dp[i-1][j][1])+1;
                }

                ans=max(ans,dp[i][j][0]*dp[i][j][1]);
            }
        }

        return ans;
    }
};
