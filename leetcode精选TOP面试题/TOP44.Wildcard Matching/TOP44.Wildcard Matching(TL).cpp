class Solution {
public:
    bool isMatch(string s,string p){
        //  对通配符处理一下 比如通配符*** 其实等价于*
        string dealp="";
        int start =0;
        for(int i=0;i<p.length();){
            if(p[i]=='*'){
                dealp+=p.substr(start,end-start+1);
                while(i<p.length()&&p[i]=='*')i++;        
                start=i;
            }
        }
        dealp+=p.substr(start);
        cout<<dealp;
        return Match(s,dealp);
    }
    bool Match(string s, string p) {
        if(p=="*")return true;
        if(s==""&&p=="")return true;
        if(s==""&&p!="")return false;
        if(s!="" &&p=="")return false;
        if(p[0]=='?'){
                   return Match(s.substr(1),p.substr(1));
        }else if(p[0]=='*'){
                   int nonStartIndex=-1;
                   for(int i=1;i<p.length();i++){
                       if(p[i]!='*'){
                           nonStartIndex=i;break;
                       }
                   }
                   if(nonStartIndex==-1)return true;
                   char nextchar=p[nonStartIndex];
                   for(int i=0;i<s.length();i++){
                        if(s[i]==nextchar||nextchar=='?'){
                            if(Match(s.substr(i),p.substr(nonStartIndex)))
                                    return true;
                        }
                   }
        }else{
           if(p[0]==s[0]){
                   return Match(s.substr(1),p.substr(1));
           }
        }
        return false;
    }
};



