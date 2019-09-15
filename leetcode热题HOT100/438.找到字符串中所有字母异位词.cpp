class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int>need;
        map<char,int>cur;
        set<char>lack;

        for(auto c:p){
            need[c]++;
            lack.insert(c);
        }

        int p1=0,p2=0;
        while(p2<p.length()){
            char tc=s[p2++];
            cur[tc]++;
            if(cur[tc]==need[tc]){
                lack.erase(tc); 
            } 
        }
        vector<int>ans;
        if(lack.empty())ans.push_back(p1);
        
        while(p2<s.length()){
            char tc=s[p2++];
            cur[tc]++;
            if(cur[tc]==need[tc])lack.erase(tc);
            tc=s[p1++];
            cur[tc]--;
            if(cur[tc]<need[tc])lack.insert(tc);
            if(lack.empty())ans.push_back(p1);
        }
        return ans;
    }
};


