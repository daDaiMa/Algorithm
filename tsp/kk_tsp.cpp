#include <bits/stdc++.h>
#define MAXN 30
using namespace std;
int N;
int dis[MAXN][MAXN];
int **dp;
int main() {
  if (!freopen("./input.txt", "r", stdin)) {
    printf("shit");
    return -1;
  }
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &dis[i][j]);
      // 如果距离输入是负数 就表示不直接相连吧～ 那距离就设置成一个较大值
      if (dis[i][j] < 0)
        dis[i][j] = INT_MAX / 2;
    }
  }

  int V = 1 << (N - 1);

  dp = new int *[V + 1];
  for (int i = 0; i <= V; i++) {
    dp[i] = new int[N + 1];
    for (int j = 0; j <= N; j++)
      dp[i][j] = INT_MAX;
  }

  // 0 0 0 0
  dp[0][0] = 0;
  for (int v = 0; v < V; v++) {
    for (int c = 1; c < N; c++) {
      // c 已经在v 中啦
      if ((1 << (c - 1)) & v)
        continue;
      if (!v) {
        int new_v = v | (1 << (c - 1));
        dp[new_v][c] = dis[0][c];
        continue;
      }
      for (int k = 1; k < N; k++) {
        if ((1 << (k - 1)) & v) {
          int new_v = v | (1 << (c - 1));
          dp[new_v][c] = min(dp[new_v][c], dp[v][k] + dis[k][c]);
        }
      }
    }
  }

  int ans = INT_MAX;
  for (int i = 0; i < N; i++)
    ans = min(ans, dp[V - 1][i] + dis[i][0]);

  printf("the ans is %d", ans);

  return 0;
}
