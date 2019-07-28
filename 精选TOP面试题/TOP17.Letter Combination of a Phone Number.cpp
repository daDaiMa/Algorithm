class Solution {
public:
    string chars[10]={
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
    };
    
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits=="")return ans;
        string cur="";
        dfs(0,ans,digits,cur);
        return ans;
    }
    void dfs(int d,vector<string>&ans,string& str,string cur){
        if(d==str.length()){
            ans.push_back(cur);
            return;
        }
        for(char c:chars[str[d]-'0']){
            stringstream ss;
            ss<<c;
            string tmp;
            ss>>tmp;
            dfs(d+1,ans,str,cur+tmp);
        }
    }
};

