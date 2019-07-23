
class Solution {
public:
    int dirx[4] = {-1, 1, 0, 0};
    int diry[4] = {0, 0, -1, 1};

    int numIslands(vector<vector<char>> &grid) {
        bool **vis = new bool *[grid.size()];
        if (grid.size() == 0)return 0;
        int i, j;
        for (i = 0; i < grid.size(); i++) {
            vis[i] = new bool[grid[0].size()];
            for(j=0;j<grid[0].size();j++)vis[i][j]=false;
        }


        int ans = 0;
        for (i = 0; i < grid.size(); i++) {
            for (j = 0; j < grid[0].size(); j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, vis);
                    ans++;
                }
            }
        }
        return ans;
    }

    void dfs(int x, int y, vector<vector<char>> &grid, bool **vis) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())return;
        if (grid[x][y] == '0')return;
        if (vis[x][y])return;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            dfs(x + dirx[i], y + diry[i], grid, vis);
        }
    }

};
