#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int scheduleCourse(vector<vector<int>> &courses) {
    int ans = 0;
    sort(courses.begin(), courses.end(),
         [](const vector<int> &a, const vector<int> &b) {
           if (a[1] == b[1])
             return a[0] < b[0];
           return a[1] < b[1];
         });
    int day = 0;
    for (auto &c : courses) {
      if (day + c[0] <= c[1]) {
        day += c[0];
        ans += 1;
      }
    }
    return ans;
  }
};
