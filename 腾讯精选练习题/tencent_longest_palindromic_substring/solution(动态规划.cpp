
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        if(!len)return "";
        vector<vector<bool>>dp(len+1,vector<bool>(len+1,0));
        dp[len-1][len-1]=true;
        for(int i=0;i<len-1;i++){
            dp[i][i]=true;
            dp[i][i+1]=s[i]==s[i+1];
        }
        for(int size=3;size<=len;size++){
            for(int i=0;i+size<=len;i++){
                dp[i][i+size-1]=dp[i+1][i+size-2]&&s[i]==s[i+size-1];
            } 
        }

        int _max=1;
        int _start=0;
        for(int i=0;i<len;i++){
            for(int j=i+_max;j<len;j++){
                if(dp[i][j]){
                    _max=j-i+1;
                    _start=i;
                }
            }
        }

        return s.substr(_start,_max);
    }
};
