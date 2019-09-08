# 第一题   

### 题目描述

题目的大概意思

你有一个安卓手鸡要设置滑动解锁

滑动解锁的最大密码长度是n 最小是m

问你有几种密码的设置方法

还有限制条件如下

```
1	2	3
4	5	6
7	8	9
```

如果滑动解锁某一段是从1->3 那么2必须是之前就已经经过的 

否则1->3不合法

同理 

4，6

2，6

1，9

3，7

……



举个例子

密码的顺序是1397 

这个就是不合法的 因为从1到3 经过了2 但是2没有在1到3之前被经过

39,97也是同理 因为6和8 也没有在此之前被经过

#### 

#### 思路

太紧张了 

直接暴力

#### code

```cpp
#include<iostream>
using namespace std;
void dfs(int d,int pre);
int m,n,ans,k;
int vis[10]={0};
int need[10][10]={0};
int	main(){
    cin>>k;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            need[i][j]=0;
    need[1][3]=need[3][1]=2;
    need[1][7]=need[7][1]=4;
    need[1][9]=need[9][1]=5;
    need[2][8]=need[8][2]=5;
    need[9][3]=need[3][9]=6;
    need[4][6]=need[6][4]=5;
    need[3][7]=need[7][3]=5;
    need[7][9]=need[9][7]=8;
    vis[0]=1;
    while(k--){
        cin>>m>>n;
        if(m>n){
            cout<<0<<endl;
            continue;
        }
        m=(m<=0)?1:m;
        n=(n>9)?9:n;
        for(int i=1;i<10;i++)vis[i]=0;
        ans=0;
        for(int i=1;i<10;i++){
            vis[i]=1;
            dfs(1,i);
            vis[i]=0;
        }
        cout<<ans<<endl;
    }
    return 0;
}

void dfs(int d,int pre){
    if(d>=m&&d<=n){
        ans++;
        if(d==n)return;
    }
    for(int i=1;i<10;i++){
        if(!vis[i]&&vis[need[pre][i]]){
            vis[i]=1;
            dfs(d+1,i);
            vis[i]=0;
        }
    }
}
```





