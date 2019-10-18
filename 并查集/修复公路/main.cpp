#include <bits/stdc++.h>

#define MAXN 1005
using namespace std;

int f[MAXN];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

bool join(int a, int b) {
  int fa = find(a), fb = find(b);
  if (fa == fb)
    return false;
  f[fa] = fb;
  return true;
}

void init() {
  for (int i = 0; i < MAXN; i++) {
    f[i] = i;
  }
}

int N, M;
struct Edge {
  int s, e, t;
};

Edge edge[100005];

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> edge[i].s >> edge[i].e >> edge[i].t;
  }
  sort(edge, edge + M, [](const Edge &a, const Edge &b) { return a.t < b.t; });
  int left = N;
  init();
  for (int i = 0; i < M; i++) {
    if (join(edge[i].s, edge[i].e)) {
      left--;
      if (left == 1) {
        cout << edge[i].t;
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}
