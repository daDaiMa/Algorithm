class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<int>stepset;
        set<string>words;
        for(auto&w:wordDict){
            stepset.insert(w.length());
            words.insert(w);
        }
        vector<int>steps(stepset.begin(),stepset.end());
        vector<string>ans;
        dfs("",s,0,ans,words,steps);
        return ans;
    }
    void dfs(string cur,string&s,int index,vector<string>&ans,set<string>&words,vector<int>&steps){
        if(index>=s.length()){
           ans.push_back(cur); 
           return;
        }
        for(int& step:steps){
            if(index+step>s.length())break;
            string tmp=s.substr(index,step);
            if(words.count(tmp)){
                dfs(cur==""?tmp:cur+" "+tmp,s,index+step,ans,words,steps);
            }
        }
    }
};

