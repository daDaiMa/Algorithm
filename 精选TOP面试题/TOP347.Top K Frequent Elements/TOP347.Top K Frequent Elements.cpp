class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        map<int, int> m;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            m[*it]++;
        }
        vector<pair<int, int>> tmp;
        vector<int> ans;
        for (auto it = m.begin(); it != m.end(); it++) {
            tmp.push_back(make_pair(it->first, it->second));
        }
        sort(tmp.begin(), tmp.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        });
        for (int i = 0; i < k; i++) {
            ans.push_back(tmp[i].first);
        }
        return ans;
    }
};