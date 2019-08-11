public:
    stack<int>sta;
    set<int>s;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>g(numCourses);
        for(auto it:prerequisites){
           g[it[1]].push_back(it[0]);
        }
        s.clear();
        vector<int>ans(0);
        for(int i=0;i<numCourses){
            if(s.count(i))continue;
            set<int>vis;
            vis.insert(i);
            s.insert(i);
            if(!topsort(i,g,vis))return ans; 
        }
        while(!sta.empty()){
            ans.push_back(sta.top());sta.pop();
        }
        return ans;
    }
    bool topsort(int c,vector<vector<int>>&g,set<int>&vis){
        for(int i:g[c]){
            if(s.count(i))continue;
            s.insert(i);
            if(vis.count(i))return false;
            sta.push(i);
            if(!topsort(i,g,vis))return false;
        }
        return true;
    }
};


