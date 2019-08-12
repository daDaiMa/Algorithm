class Solution {
public:
    bool isMatch(string s,string p){
        int sp=0;int pp=0;
        int preStarIndex=-1;
        int preMatchIndex=0;
        while(sp<s.length()){
            if(p[pp]=='?'||p[pp]==s[sp]){
                pp++;
                sp++;
            }
            else if(sp<s.length()&&p[pp]=='*'){
                preMatchIndex=sp;
                preStarIndex=pp;
                pp++;
            }else if(preStarIndex!=-1){
                sp=preMatchIndex=preMatchIndex+1;
                pp=preStarIndex+1;
            }else{
                return false;
            }
        }
        for(;pp<p.length();pp++)if(p[pp]!='*')return false;
        return true;
    }
};



