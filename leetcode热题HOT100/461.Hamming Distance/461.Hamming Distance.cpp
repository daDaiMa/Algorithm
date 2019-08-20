class Solution {
public:
    int hammingDistance(int x, int y) {
        int m=max(x,y);
        int n=min(x,y);
        int ans=0;
        while(m){
           if(((m&1)^(n&1)))ans++;
           m>>=1;
           n>>=1;
        }
        return ans;
    }
};

