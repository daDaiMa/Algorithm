#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    if (nums.size() <= 1) {
      return nums;
    }

    int numsize = nums.size();

    vector<vector<int>> vs(numsize, vector<int>(0));
    sort(nums.begin(), nums.end(),
         [](const int &a, const int &b) { return a < b; });

    for (int i = 0; i < numsize; i++)
      vs[i].push_back(nums[i]);
    vector<int> dp(numsize, 1);
    for (int i = 1; i < numsize; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0) {
          if (dp[i] >= dp[j] + 1) {
            //
          } else {
            dp[i] = dp[j] + 1;
            vs[i] = vs[j];
            vs[i].push_back(nums[i]);
          }
        }
      }
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
