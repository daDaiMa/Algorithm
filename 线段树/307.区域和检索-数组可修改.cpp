#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  int s, e;
  Node *left;
  Node *right;
  Node(int val, int s, int e) {
    this->s = s;
    this->e = e;
    this->val = val;
  }
};

class NumArray {
public:
  Node *tree;
  int size;
  NumArray(vector<int> &nums) {
    size = nums.size();
    tree = build(0, nums.size() - 1, nums);
  }

  Node *build(int s, int e, vector<int> &nums) {
    if (s > e)
      return NULL;
    if (s == e)
      return new Node(nums[s], s, e);
    int mid = (s + e) / 2;
    Node *root = new Node(0, s, e);
    root->left = build(s, mid, nums);
    root->right = build(mid + 1, e, nums);
    root->val = root->left->val + root->right->val;
    return root;
  }

  void update(int i, int val) { update_util(tree, i, val); }

  void update_util(Node *root, int i, int val) {
    if (root->s == i && root->e == i) {
      root->val = val;
      return;
    }
    int mid = (root->s + root->e) / 2;
    if (i > mid) {
      update_util(root->right, i, val);
    } else {
      update_util(root->left, i, val);
    }
    root->val = root->left->val + root->right->val;
  }

  int sumRange(int i, int j) { return sum(tree, i, j); }

  int sum(Node *root, int s, int e) {
    if (s <= root->s && e >= root->e)
      return root->val;
    int mid = (root->s + root->e) / 2;
    if (e <= mid)
      return sum(root->left, s, e);
    if (s > mid)
      return sum(root->right, s, e);
    return sum(root->left, s, mid) + sum(root->right, mid + 1, e);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
