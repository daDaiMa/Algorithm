#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int rank;
  int val; // 携带的附加信息 可有可无
  int parent;
};

class UnionSet {
public:
  Node *node;
  UnionSet(int size) {
    node = new Node[size + 1];
    for (int i = 0; i <= size; i++) {
      node[i].rank = 0;
      node[i].parent = i;
    }
  }
  int find(int n) {
    if (node[n].parent == n)
      return n;
    node[n].parent = find(node[n].parent);
    return node[n].parent;
  }
  void join(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb)
      return;

    if (node[pa].rank >= node[pb].rank) {
      if (node[pa].rank == node[pa].rank) {
        node[pa].rank += 1;
      }
      node[pb].parent = pa;
    } else {
      node[pa].parent = pb;
    }
  }
};

class Solution {
public:
  int regionsBySlashes(vector<string> &grid) {
    int len = grid.size();
    UnionSet uset(len * len * 4);
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        char c = grid[i][j];
        int root = (i * len + j) * 4;
        if (c != '\\') {
          uset.join(root, root + 1);
          uset.join(root + 2, root + 3);
        }
        if (c != '/') {
          uset.join(root, root + 2);
          uset.join(root + 1, root + 3);
        }

        if (i + 1 < len) {
          uset.join(root + 3, root + len * 4);
        }

        if (i - 1 >= 0) {
          uset.join(root, root - len * 4 + 3);
        }

        if (j + 1 < len) {
          uset.join(root + 2, root + 4 + 1);
        }

        if (j - 1 >= 0) {
          uset.join(root + 1, root - 4 + 2);
        }
      }
    }

    int res = 0;
    for (int i = 0; i < len * len * 4; i++) {
      if (uset.find(i) == i)
        res++;
    }
    return res;
  }
};
