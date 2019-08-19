class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            for(int j=i,k=i;j<s.length()&&k>=0;j++,k--){
                if(s[j]==s[k])ans++;
                else break;
            }
            for(int j=i,k=i-1;j<s.length()&&k>=0;j++,k--){
                if(s[j]==s[k])ans++;
                else break;
            }
        }
        return ans;
    }
};
