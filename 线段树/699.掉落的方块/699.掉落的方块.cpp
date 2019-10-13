#include <bits/stdc++.h>

using namespace std;

struct Node {
  int left, right, sum, add;
  Node *ls, *rs;
  Node(int l, int r) : left(l), right(r) { sum = add = 0, ls = rs = NULL; }

  void update(int l, int r, int max) {
    if (left == right) {
      sum = max;
      return;
    }
    int mid = (left + right) / 2;
    if (r <= mid)
      ls->update(l, r, max);
    else if (l > mid)
      rs->update(l, r, max);
    else {
      ls->update(l, mid, max);
      rs->update(mid + 1, r, max);
    }
    sum = max;
  }

  int query(int l, int r) {
    if (l <= left && r >= right)
      return sum;
    int mid = (right + left) / 2;
    if (r <= mid)
      return ls->query(l, r);
    if (l > mid)
      return rs->query(l, r);
    return max(ls->query(l, mid), rs->query(mid + 1, r));
  }
};

Node *build(int l, int r) {
  if (l > r)
    return NULL;
  if (l == r)
    return new Node(l, r);
  int mid = (l + r) / 2;
  Node *node = new Node(l, r);
  node->ls = build(l, mid);
  node->rs = build(mid + 1, r);
  return node;
}

class Solution {
public:
  vector<int> fallingSquares(vector<vector<int>> &positions) {
    vector<int> ans;
    set<int> s_tmp;
    map<int, int> disperse;
    for (auto &v : positions) {
      s_tmp.insert(v[0]);
      s_tmp.insert(v[0] + v[1] - 1);
    }
    int index = 0;
    for (auto n : s_tmp) {
      disperse[n] = index++;
    }

    int cur_max = 0;
    Node *tree = build(0, disperse.size() - 1);
    for (auto &chunk : positions) {
      int left = disperse[chunk[0]];
      int right = disperse[chunk[0] + chunk[1] - 1];
      int max_height = tree->query(left, right) + chunk[1];
      tree->update(left, right, max_height);
      cur_max = max(cur_max, max_height);
      ans.emplace_back(cur_max);
    }

    return ans;
  }
};

int main() {
  vector<vector<int>> v;
  v.emplace_back(vector<int>({1, 2}));
  v.emplace_back(vector<int>({2, 3}));
  v.emplace_back(vector<int>({6, 1}));
  Solution s;
  s.fallingSquares(v);
  return 0;
}
