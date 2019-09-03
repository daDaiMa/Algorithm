class Solution {
public:
    vector<int> ans;
    vector<int> vis;

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> g(numCourses);
        for (auto it:prerequisites) {
            g[it[1]].push_back(it[0]);
        }
        vis.assign(numCourses, 0);
        ans.assign(numCourses, 0);
        int course = numCourses - 1;
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                course = topsort(course, i, g);
                if (course == -2)return vector<int>(0);
            }
        }
        return ans;
    }

    int topsort(int n, int cur, vector<vector<int>> &g) {
        vis[cur] = -1;
        for (int next : g[cur]) {
            if (vis[next] == -1)return -2;
            if (vis[next] == 1)continue;
            n = topsort(n, next, g);
            if (n == -2)return -2;
        }
        vis[cur] = 1;
        ans[n] = cur;
        return --n;
    }
};
