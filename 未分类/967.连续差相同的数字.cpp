
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int>ans;
        for(int i=(N==1?0:1);i<10;i++){
            dfs(ans,N-1,K,i);
        }
        return ans;
    }

    void dfs(vector<int>&ans,int d,int k,int val){
        if(d==0){
            ans.push_back(val);
            return;
        } 

        int last=val%10;
        if(last+k<10)
            dfs(ans,d-1,k,val*10+last+k);
        
        // k==0 下边的这个和上边的就一样了
        if(k==0)
            return;
        
        if(last-k>=0)
            dfs(ans,d-1,k,val*10+last-k);
        
    }
};






















