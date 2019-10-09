#include <bits/stdc++.h>

#define MAXN 100005
using namespace std;

inline int ls(int p) { return p << 1; }

inline int rs(int p) { return p << 1 | 1; }

struct node {
  int l, r, update;
  long long sum;
  node() {}
  node(int l, int r, long long sum) : l(l), r(r), sum(sum) { update = 0; }
};

node s[MAXN * 4 + 2];

int nums[MAXN];
int N, M;

void build(int arr[], int root, int l, int r) {
  s[root].l = l;
  s[root].r = r;
  if (l == r) {
    s[root].sum = arr[l];
    return;
  }
  int mid = (r + l) >> 1;
  build(arr, ls(root), l, mid);
  build(arr, rs(root), mid + 1, r);
  s[root].sum = s[ls(root)].sum + s[rs(root)].sum;
}

void push_down(int root) {
  s[ls(root)].update += s[root].update;
  s[ls(root)].sum += (s[ls(root)].r - s[ls(root)].l + 1) * s[root].update;
  s[rs(root)].update += s[root].update;
  s[rs(root)].sum += (s[rs(root)].r - s[rs(root)].l + 1) * s[root].update;
  s[root].update = 0;
}

void add(int root, int l, int r, int x) {
  if (s[root].l >= l && s[root].r <= r) {
    s[root].sum += (r - l + 1) * x;
    s[root].update += x;
    return;
  }
  push_down(root);
  int mid = (s[root].l + s[root].r) >> 1;
  if (l > mid)
    add(rs(root), l, r, x);
  else if (r <= mid)
    add(ls(root), l, r, x);
  else {
    add(ls(root), l, mid, x);
    add(rs(root), mid + 1, r, x);
  }
  s[root].sum = s[ls(root)].sum + s[rs(root)].sum;
}

/*
void add(int root, int l, int r, int x) {
  if (s[root].l == l && s[root].l == s[root].r) {
    s[root].sum += x;
    return;
  }
  int mid = (s[root].l + s[root].r) >> 1;
  if (l > mid)
    add(rs(root), l, r, x);
  else if (r <= mid)
    add(ls(root), l, r, x);
  else {
    add(ls(root), l, mid, x);
    add(rs(root), mid + 1, r, x);
  }
  s[root].sum = s[ls(root)].sum + s[rs(root)].sum;
}
*/

long long find(int root, int l, int r) {
  if (l > s[root].r || r < s[root].l)
    return 0;
  if (l <= s[root].l && r >= s[root].r) {
    return s[root].sum;
  }
  push_down(root);
  int mid = (s[root].l + s[root].r) / 2;
  if (r <= mid)
    return find(ls(root), l, r);
  if (l > mid)
    return find(rs(root), l, r);
  return find(ls(root), l, mid) + find(rs(root), mid + 1, r);
}

int main() {

  if (!freopen("../input.txt", "r", stdin)) {
    printf("open failed");
    exit(1);
  }

  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++)
    scanf("%d", &nums[i]);
  build(nums, 1, 1, N);
  while (M--) {
    int op, x, y, k;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d%d", &x, &y, &k);
      add(1, x, y, k);
    } else {
      scanf("%d%d", &x, &y);
      printf("%lld\n", find(1, x, y));
    }
  }

  return 0;
}
