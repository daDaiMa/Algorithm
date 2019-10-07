#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int ans = 0;
  int _lower;
  int _upper;
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    if (nums.size() == 0)
      return 0;
    vector<long long> sum = {0};
    for (int i = 0; i < nums.size(); i++)
      sum.push_back(sum.back() + nums[i]);
    _lower = lower;
    _upper = upper;
    ans = 0;
    merge_sort(sum, 0, sum.size());
    return ans;
  }

  void merge_sort(vector<long long> &nums, int l, int r) {
    if (r - l <= 1)
      return;
    int m = (l + r) / 2;
    merge_sort(nums, l, m);
    merge_sort(nums, m, r);

    int l2;

    int right1 = m, right2 = m;
    for (int left = l; left < m; left++) {
      while (right1 < r && nums[right1] - nums[left] < _lower)
        ++right1;
      while (right2 < r && nums[right2] - nums[left] <= _upper)
        ++right2;
      ans += (right2 - m) - (right1 - m);
    }

    vector<long long> tmp;
    int l1 = l;
    l2 = m;
    while (l < m && l2 < r) {
      if (nums[l] > nums[l2]) {
        tmp.push_back(nums[l2]);
        l2++;
      } else {
        tmp.push_back(nums[l]);
        l++;
      }
    }
    while (l < m) {
      tmp.push_back(nums[l++]);
    }
    while (l2 < r) {
      tmp.push_back(nums[l2++]);
    }

    int idx = 0;
    for (int i = l1; i < r; i++) {
      nums[i] = tmp[idx++];
    }
    for (auto x : nums) {
      printf("%lld,", x);
    }
    cout << endl;
  }
};
