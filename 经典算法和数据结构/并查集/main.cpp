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
