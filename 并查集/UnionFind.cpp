#include <iostream>

using namespace std;

class Union{
    int* set;
    Union(int n){
        set=new int[n];
        for(int i=0;i<n;i++){
            set[i]=i; 
        }
    } 
    void join(int a,int b){
        int fa=find(a);
        int fb=find(b);
        if(fa==fb)return;

        set[b]=fa;
    }
    int find(int a){
        int t=a;
        while(f[t]!=t){
            f[t]=f[f[t]];
            t=f[t];
        }
        return t;
    }
}

int main(){
    return 0;
}
