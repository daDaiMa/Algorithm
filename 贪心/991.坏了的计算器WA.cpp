class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X==Y)return 0;
        if(X>Y)return X-Y;
        int ans=0;
        while(X*2<Y){
            ans++;
            X*=2;
        }
        // X<Y && X*2>Y
        int mul=X*2-Y+1;
        int dec=X-(Y%1?Y+1:Y)/2+Y%2+1; 

        return ans+min(mul,dec);
    }
};
