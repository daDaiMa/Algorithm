#include <bits/stdc++.h>
#define MAXN 205
using namespace std;

struct Node {
  int val;
  int weight;
  Node() {}
};

class Solution {
public:
  Node f[MAXN];
  void init() {
    for (int i = 0; i < MAXN; i++)
      f[i].val = i, f[i].weight = 0;
  }
  void join(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    if (fa == fb)
      return;
    if (f[fa].weight >= f[fb].weight) {
      if (f[fa].weight == f[fb].weight)
        f[fa].weight++;
      f[fb].val = fa;
    } else {
      f[fa].val = fb;
    }
  }
  int find(int c) {
    if (f[c].val == c)
      return c;
    f[c].val = find(f[c].val);
    return f[c].val;
  }
  int findCircleNum(vector<vector<int>> &M) {
    init();
    for (int i = 0; i < M.size(); i++)
      for (int j = 0; j < M[i].size(); j++)
        if (M[i][j])
          join(i, j);
    int ans = 0;
    for (int i = 0; i < M.size(); i++)
      if (f[i].val == i)
        ans++;
    return ans;
  }
};
