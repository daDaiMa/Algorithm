class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans=0;
        while(X<Y){
            ans+=1+Y%2;
            Y=(Y+1)>>1;
        }
        return ans + X -Y;
    }
};

