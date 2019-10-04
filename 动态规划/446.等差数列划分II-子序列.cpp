#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &A) {
    int size = A.size();
    if (size <= 1)
      return 0;
    map<long long, int> dp[A.size()];
    int ans = 0;
    for (int i = 1; i < size; i++) {
      for (int j = 0; j < i; j++) {
        long long delta = (long long)A[i] - (long long)A[j];
        int sum = 0;
        if (dp[j].count(delta)) {
          sum = dp[j][delta];
        }
        dp[i][delta] += sum + 1;
        ans += sum;
      }
    }
    return ans;
  }
};
