#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int scheduleCourse(vector<vector<int>> &courses) {
    sort(courses.begin(), courses.end(),
         [](const vector<int> &a, const vector<int> &b) {
           if (a[1] == b[1])
             return a[0] < b[0];
           return a[1] < b[1];
         });
    priority_queue<int> cs;
    int day = 0;
    for (int i = 0; i < courses.size(); i++) {
      if (day + courses[i][0] <= courses[i][1]) {
        day += courses[i][0];
        cs.push(courses[i][0]);
      } else if (!cs.empty() && cs.top() > courses[i][0]) {
        day += courses[i][0] - cs.top();
        cs.pop();
        cs.push(courses[i][0]);
      }
    }
    return cs.size();
  }
};
