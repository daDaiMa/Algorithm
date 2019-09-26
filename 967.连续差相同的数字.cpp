
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int>ans({0,1,2,3,4,5,6,7,8,9});
        for(int i=1;i<N;i++){
            vector<int>cur;
            for(int num:ans){
                if(!num)continue;
                if(num%10+K<10){
                    cur.push_back(num*10+num%10+K);
                }
                if(!K)continue;
                if(num%10-K>=0){
                    cur.push_back(num*10+num%10-K);
                }
            }
            swap(ans,cur);
        }
        return ans;
    }
};

