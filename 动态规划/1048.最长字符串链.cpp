c
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string&a,string&b){
            return a.length()<b.length();
        });
        vector<int>dp(words.size());
        int ans=1;
        dp[0]=1;
        for(int i=1;i<words.size();i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(ok(words[j],words[i])){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            } 
            ans=max(ans,dp[i]);
        } 
        return ans;
    }
    bool ok(string&a,string&b){
        int lena=a.length();
        int lenb=b.length();

        if(lena!=lenb-1)
            return false;
        
        int stra=0,strb=0,count=0;
        
        while(stra<lena){
            if(a[stra]!=b[strb]){
                if(count)return false;
                strb++;
                count++;
            }else{
                stra++;
                strb++;
            }
        }
        return true;
    }
};
;
