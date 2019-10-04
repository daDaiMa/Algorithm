#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    if (nums.size() <= 1) {
      return nums;
    }
    vector<vector<int>> vs;
    sort(nums.begin(), nums.end(),
         [](const int &a, const int &b) { return a < b; });
    int cur_max = 1;
    int left = nums.size();
    for (auto num : nums) {
      int size = vs.size();
      for (int i = 0; i < size; i++) {
        if (num % vs[i].back() == 0) {
          if (left + vs[i].size() < cur_max) {
            continue;
          }
          vector<int> tmp(vs[i]);
          tmp.push_back(num);
          vs.push_back(tmp);
        } else if (num < vs[i].back()) {
          int len = vs[i].size();
          if (len > 1) {
            vs[i][len - 1] = num;
          }
        }
        cur_max = cur_max > vs[i].size() ? cur_max : vs[i].size();
      }

      if (left > cur_max)
        vs.push_back(vector<int>{num});
      left--;
    }
    int max_size = 0;
    int ans = 0;
    for (int i = 0; i < vs.size(); i++) {
      if (vs[i].size() > max_size) {
        ans = i;
        max_size = vs[i].size();
      }
    }
    return vs[ans];
  }
};
