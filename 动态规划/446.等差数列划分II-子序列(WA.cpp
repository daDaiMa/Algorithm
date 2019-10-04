#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &A) {
    // dp[i][j] 表示以第i个元素为结尾的 以j为差的等差数列
    // map<int,int>*dp=new map<int,int>[A.size()];
    int size = A.size();

    if (size <= 1)
      return 0;
    sort(A.begin(), A.end(), [](const int a, const int b) { return a < b; });
    map<int, int> dp[A.size()];
    map<int, int> _max[A.size()];

    int ans = 0;
    for (int i = 1; i < size; i++) {
      for (int j = 0; j < i; j++) {
        if (A[j] < 0 && A[i] > A[j] + (2 ^ 30))
          continue;

        int delta = A[i] - A[j];
        if (!_max[j][delta]) {
          _max[j][delta] = 1;
        }
        int len = (_max[i][delta] = max(_max[i][delta], _max[j][delta] + 1));
        if (len == 3) {
          dp[i][delta] = 1;
          printf("_max[%d][%d]=%d,dp[%d][%d]=%d\n", i + 1, delta,
                 _max[i][delta], i + 1, delta, dp[i][delta]);
        } else if (len > 3) {
          dp[i][delta] += dp[j][delta] + 1;
          printf("_max[%d][%d]=%d,dp[%d][%d]=%d,dp[%d][%d]=%d\n", i + 1, delta,
                 _max[i][delta], i + 1, delta, dp[i][delta], j + 1, delta,
                 dp[j][delta]);
        } else {
          continue;
        }

        ans += dp[i][delta];
      }
    }
    return ans;
  }
};
