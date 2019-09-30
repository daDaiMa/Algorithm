#include <iostream>

using namespace std;

int pow(int a,int n){
    if(!a)return 0;
    if(n==0)return 1;
    if(n==1)return a;
    int half=pow(a,n/2);
    if(n%2)
        return half*half*a;
    return half*half;
}

int main(){
    printf("4^7=%d,3^8=%d",pow(4,7),pow(3,8));
    return 0;
}
