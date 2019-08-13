class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>ans(num+1);
        for(int i=1;i<=num;i*=2){
            for(int j=0;j<=num;j++){
                if(i&j)ans[j]++;
            }
        }
        return ans;
    }
};


