class Solution {
public:
    long long factorial[10];
    long long target;
    string ans;
    bool vis[10];
    string getPermutation(int n, int k) {
        factorial[0]=1;
        for(int i=1;i<10;i++) 
            factorial[i]=factorial[i-1]*i;
        target=k;
        memset(vis,0,sizeof(vis));
        dfs(0,n);
        return ans;
    }

    void dfs(int deep,int n){
        if(deep==n){
            return;
        }
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            if(target>factorial[n-deep-1]){
                target-=factorial[n-deep-1];
                continue;
            }else if (target==factorial[n-deep-1]){
                ans+=to_string(i);
                vis[i]=true;
                for(int j=n;j>0;j--){
                    if(!vis[j])ans+=to_string(j);
                }
                return;
            }else{
                ans+=to_string(i);
                vis[i]=true;
                dfs(deep+1,n);
                return ;
            }
        } 
    }
};

