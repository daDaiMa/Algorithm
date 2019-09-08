# 第二题   

随便输进来几个数

然后把全排序输出

😂水题emmm



#### code

```cpp
#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int a;
    vector<int> v;
    while (cin>>a) {
        v.push_back(a);
    }
    if (!v.size())return 0;
    long long out=0;
    for (auto &x:v) {
        out=out*10+x;
    }
    printf("%lld ",out);

    while (next_permutation(v.begin(), v.end())) {
        out=0;
        for (auto &x:v) {
            out=out*10+x;
        }
        printf("%lld ",out);
    }
}
```

