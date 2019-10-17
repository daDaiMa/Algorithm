#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minSwapsCouples(vector<int> &row) {
    int ans = 0;
    for (int i = 0; i < row.size() - 1; i += 2) {
      int op = row[i] ^ 1;
      if (row[i + 1] != op) {
        for (int j = i + 2; j < row.size(); j++) {
          if (row[j] == op) {
            swap(row[i + 1], row[j]);
            ans++;
            break;
          }
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> v({0, 2, 1, 3});
  cout << s.minSwapsCouples(v);
  return 0;
}
