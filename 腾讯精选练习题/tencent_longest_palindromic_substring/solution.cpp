
class Solution {
public:
    string longestPalindrome(string s) {
        if(!s.length())return "";
        int _max=1;
        int _start=0;
        int _end=0;
        for(int i=1;i<s.length();i++){
            int start=i;
            int end=i;
            for(;start>=0&&end<s.length();){ 
                if(s[start]!=s[end])break;   
                if(_max<end-start+1){
                    _max=end-start+1;
                    _start=start;
                    _end=end;
                }
                start--;
                end++;
            }
            start=i;
            end=i-1;
            for(;start>=0&&end<s.length();){ 
                if(s[start]!=s[end])break;   
                if(_max<end-start+1){
                    _max=end-start+1;
                    _start=start;
                    _end=end;
                }
                start--;
                end++;
            }
        }
        return s.substr(_start,_end-_start+1); 
    }
};
