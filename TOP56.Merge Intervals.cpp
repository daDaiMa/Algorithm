
class Solution {

public:
    bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.size() == 0) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        int _min = intervals[0][0];
        int _max = intervals[0][1];
        for (vector<int> current:intervals) {
            if (current[0] > _max) {
                ans.push_back(vector<int>{_min, _max});
                _min = current[0];
                _max = current[1];
            }else{
                _max = max(_max,current[1]);
            }
        }
        ans.push_back(vector<int>{_min,_max});
        return ans;
    }
};
