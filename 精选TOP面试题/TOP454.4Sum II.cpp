class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        // 先A和B合并，C和D合并
        map<int,int> AB;
        map<int,int> CD;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                AB[A[i] + B[j]]++;
                CD[C[i] + D[j]]++;
            }
        }
        long long ans = 0;
        for(auto it=AB.begin();it!=AB.end();it++){
            if(CD.count(0-it->first)){
                ans+=CD[0-it->first]*it->second;
            }
        }
        return ans;
    }
};
