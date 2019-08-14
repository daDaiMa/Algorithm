class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            vector<int>dp(grid[0].begin(),grid[0].end());
            for(int i=1;i<dp.size();i++)dp[i]+=dp[i-1];
            for(int i=1;i<grid.size();i++)
                for(int j=0;j<grid[i].size();j++){
                    if(j){
                        dp[j]=min(dp[j],dp[j-1])+grid[i][j];
                    }else{
                        dp[j]+=grid[i][j];
                    }
                }
            return dp.back();
        }
};
