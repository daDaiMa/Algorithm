#include <bits/stdc++.h>
using namespace std;

int n;           // 物品数量
int *val, *cost; // cost and weight
int **DP;
int V; // 背包容量

void read() {
  cin >> n >> V;
  cost = new int[n + 1];
  val = new int[n + 1];
  DP = new int *[n + 1];
  DP[0] = new int[V + 1];
  memset(DP[0], 0, sizeof(int) * (n + 1));
  for (int i = 1; i <= n; i++) {
    cin >> cost[i] >> val[i];
    DP[i] = new int[V + 1];
    memset(DP[i], 0, sizeof(int) * (n + 1));
  }
}

inline int dp(int i, int v) { return v < 0 ? INT_MIN : DP[i][v]; }

void solve() {
  for (int i = 1; i <= n; i++)
    for (int v = 0; v <= V; v++) {
      if (v < cost[i])
        DP[i][v] = DP[i - 1][v];
      else
        DP[i][v] = DP[i - 1][v] > DP[i][v - cost[i]] + val[i]
                       ? DP[i - 1][v]
                       : DP[i][v - cost[i]] + val[i];
    }
  printf("the ans is %d\n", DP[n][V]);
}

void statistics() {
  map<int, int> num;
  int v = V;
  for (int i = n; i > 0;) {
    if (DP[i][v] == DP[i - 1][v] || v < cost[i]) {
      printf("第%d件物品取%d个\n", i, num[i]);
      i--;
    } else if (DP[i][v] == DP[i][v - cost[i]] + val[i]) {
      v -= cost[i];
      num[i]++;
    }
  }
}

int main() {
  if (!freopen("./point.txt", "r", stdin)) {
    printf("open file failed exit -1");
    exit(-1);
  }
  read();
  solve();
  statistics();
  return 0;
}
