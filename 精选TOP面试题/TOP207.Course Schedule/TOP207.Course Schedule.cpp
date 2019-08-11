class Solution {
public:
    set<int>s;
    set<int>c;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>g(numCourses+1);
        for(auto p:prerequisites){
            g[p[0]].push_back(p[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(s.count(i))continue;
            s.insert(i);
            if(!topSort(i,g))return false;
        }
        return true;
    }
    bool topSort(int n,vector<vector<int>>& g){
        if(g[n].size()==0){
            return true;
        }
        for(int cs:g[n]){
            if(c.count(cs))return false;
            c.insert(cs);
            s.insert(cs);
            topSort(cs,g);
            c.erase(cs);
        }
    }
};

