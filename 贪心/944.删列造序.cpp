class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int ans=0;
        for(int i=0;i<A[0].length();i++){
            for(int j=1;j<A.size();j++){
                if(A[j][i]<A[j-1][i]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};