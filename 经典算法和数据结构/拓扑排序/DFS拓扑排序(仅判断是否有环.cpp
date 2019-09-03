
class Solution {
public:
    int* vis; // 存放访问情况;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>g(numCourses,vector<int>(0));    
        for(auto&c:prerequisites){
            g[c[1]].push_back(c[0]);
        } 
        vis=new int[numCourses];
        memset(vis,0,sizeof(int)*numCourses);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]&&!topology(i,g))return false;
        }
        return true;
    }

    bool topology(int start,vector<vector<int>>& g){
        if(vis[start]==-1)return false;
        vis[start]=-1;
        for(auto&next:g[start]){
            if(vis[next]!=1&&!topology(next,g))return false;
        }
        vis[start]=1;
        return true;
    }
};
