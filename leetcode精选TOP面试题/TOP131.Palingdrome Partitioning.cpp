
class Solution {
public:
    map<string, bool> m;
    vector<vector<string>> ans;
    vector<string> curr;

    vector<vector<string>> partition(string s) {
        m.clear();
        curr.clear();
        ans.clear();
        dfs(s, 0, s.length());
        return ans;
    }

    void dfs(string &s, int start, int end) {
        if (start == end) {
            ans.push_back(curr);
            return;
        }
        for (int step = 1; step + start <= end; step++) {
            if (judge(s, start, start + step)) {
                string substr = s.substr(start, step);
                curr.push_back(substr);
                dfs(s, start + step, end);
                curr.pop_back();
            }
        }
    }

    bool judge(string &s, int start, int end) {
        if (end - start == 1) {
            return true;
        }
        string substr = s.substr(start, end - start);
        if (m.count(substr))return m[substr];
        int i = start;
        int j = end - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                m[substr] = false;
                return false;
            }
            i++;
            j--;
        }
        return m[substr] = true;
    }

};
