#include <bits/stdc++.h>

#define MAXN 1005
using namespace std;

struct Node {
    int w, v;

    Node() {}
};

Node f[MAXN];

int find(int x) {
    if (f[x].v == x)
        return x;
    f[x].v = find(f[x].v);
    return f[x].v;
}

bool join(int a, int b) {
    int va = find(a);
    int vb = find(b);
    if (va == vb)
        return false;
    if (f[a].w >= f[b].w) {
        if (f[a].w == f[b].w)
            f[a].w += 1;
        f[b].v = va;
    } else {
        f[a].v = vb;
    }
    return true;
}

void init() {
    for (int i = 0; i < MAXN; i++) {
        f[i].v = i;
        f[i].w = 0;
    }
}

int N, M;
struct Edge {
    int s, e, t;
};

Edge edge[100005];

int main() {
    freopen("testdata.in", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> edge[i].s >> edge[i].e >> edge[i].t;
    }
    sort(edge, edge + M, [](const Edge &a, const Edge &b) { return a.t < b.t; });
//    for (int i = 0; i < M; i++) {
//        printf("start=%d,end=%d,time=%d\n", edge[i].s , edge[i].e , edge[i].t );
//    }
//    return 0;
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