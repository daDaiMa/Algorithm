class Solution {
public:
    vector<vector<int>> g;
    int *vis;
    int *top;

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        g.assign(numCourses, vector<int>(0));
        vis = new int[numCourses];
        top = new int[numCourses];
        for (int i = 0; i < numCourses; i++)vis[i] = 0;
        for (auto c : prerequisites) {
            g[c[1]].push_back(c[0]);
        }
        int course = numCourses - 1;
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                course = topological(course, i);
                if (course == -2)return false;
            }
        }

       // for (int i = 0; i < numCourses; i++) {
       //     cout << top[i] << " ";
       // }

        return true;
    }

    int topological(int num, int cur) {
        vis[cur] = 1;
        for (int next:g[cur]) {
            if (vis[next] == -1)continue;
            if (vis[next] == 1)return -2;
            num = topological(num, next);
            if (num == -2)return -2;
        }
        top[num] = cur;
        vis[cur] = -1;
        return --num;
    }
};