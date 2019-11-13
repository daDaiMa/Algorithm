#include <bits/stdc++.h>
#define MAXN 30
using namespace std;
int N;
double dis[MAXN][MAXN];
double **dp;

void input_point() {
  scanf("%d", &N);
  vector<pair<int, int> > point(N);
  int a, b;
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &a, &b);
    point[i] = make_pair(a, b);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (i == j)
        dis[i][j] = 0;
      else {
        int deltaX = point[i].first - point[j].first;
        int deltaY = point[i].second - point[j].second;
        dis[i][j] = dis[j][i] = sqrt(deltaX * deltaX + deltaY * deltaY);
      }
    }
  }
}

void input_dis() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%lf", &dis[i][j]);
      // 如果距离输入是负数 就表示不直接相连吧～ 那距离就设置成一个较大值
      if (dis[i][j] < 0)
        dis[i][j] = 0.5 * INT_MAX;
    }
  }
}
int main() {
  if (!freopen("./point.txt", "r", stdin)) {
    printf("shit");
    return -1;
  }

  input_point();
  //input_dis();

  int V = 1 << (N - 1);

  dp = new double *[V + 1];
  for (int i = 0; i <= V; i++) {
    dp[i] = new double[N + 1];
    for (int j = 0; j <= N; j++)
      dp[i][j] = 1.0 * INT_MAX;
  }

  map<pair<int, int>, int> path; // pair<set,i> pre step of i is j

  // 0 0 0 0            从 0 出发
  dp[0][0] = 0;
  for (int v = 0; v < V; v++) {
    for (int c = 1; c < N; c++) {
      // c 已经在v 中啦
      if ((1 << (c - 1)) & v)
        continue;
      if (!v) {
        int new_v = v | (1 << (c - 1));
        dp[new_v][c] = dis[0][c];
        path[make_pair(new_v, c)] = c;
        continue;
      }
      for (int k = 1; k < N; k++) {
        if ((1 << (k - 1)) & v) {
          int new_v = v | (1 << (c - 1));
          dp[new_v][c] = min(dp[new_v][c], dp[v][k] + dis[k][c]);
          if (dp[new_v][c] == dp[v][k] + dis[k][c]) {
            path[make_pair(new_v, c)] = k;
          }
        }
      }
    }
  }

  double ans = 1.0 * INT_MAX;
  int ans_index = 1;
  for (int i = 1; i < N; i++) {
    if (ans > dp[V - 1][i]) {
      ans = dp[V - 1][i];
      ans_index = i;
    }
  }

  printf("the ans is %lf", ans);
  // return 0;
  // 计算路径
  int v = V - 1;
  int cur = ans_index; // 从 0 - cur 的路径
  stack<int> p;
  cout << endl;
  while (v) {
    p.push(cur);
    int pre = path[make_pair(v, cur)];
    v &= ~(1 << (cur - 1));
    cur = pre;
  }
  printf("0");
  while (!p.empty()) {
    printf("==>%d", p.top());
    p.pop();
  }

  return 0;
}
