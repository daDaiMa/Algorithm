// 看了题解。如果是自己写，肯定没这么优雅😖。
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p=="")return s=="";
        bool firstMatch=s!=""&&((s[0]==p[0])||p[0]=='.');
        if(p.size()>1&&p[1]=='*'){
            return isMatch(s,p.substr(2))||(firstMatch&&isMatch(s.substr(1),p));
        }
        return firstMatch&&isMatch(s.substr(1),p.substr(1));
    }
};
