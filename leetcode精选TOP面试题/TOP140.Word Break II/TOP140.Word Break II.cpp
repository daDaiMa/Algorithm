class Solution {
public:
    unordered_map<string,vector<string>>um;
    unordered_set<string>us;
    vector<int>steps;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<int>tmps; 
        for(string&w:wordDict){
            tmps.insert(w.length());
            us.insert(w);
        }
        steps.assign(tmps.begin(),tmps.end());
        return get(s);
        
    }
    vector<string> get(string s){
       if(s=="")return vector<string>({});
       if(um.count(s))return um[s];
       vector<string>ans;
       for(auto step:steps){
            if(step>s.length())break;
            string prefix = s.substr(0,step);
            if(!us.count(prefix))continue;
            if(step==s.length()){
                ans.push_back(prefix);
                break;
            }
            auto res=get(s.substr(step));
            if(res.size()==0)continue;
            for(string& str:res){
                ans.push_back(prefix+" "+str);
            }
        }
        um[s]=ans;
        return ans;
    }
};


