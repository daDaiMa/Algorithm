
class Solution {
public:
    vector<vector<int>>ans;
    int* vis;
    int size;
    vector<int>cur;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       if(!nums.size())return ans;
       vis=new int[nums.size()+1];
       memset(vis,0,sizeof(int)*nums.size()+1);
       size=nums.size();
       sort(nums.begin(),nums.end());
       cur.assign(size,0);
       dfs(0,nums);
       return ans;
    }
    void dfs(int index,vector<int>& nums){
        if(index==size){
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<size;i++){
            if(vis[i])continue;
            if(i&&nums[i]==nums[i-1]&&!vis[i-1])continue;
            vis[i]=1;
            cur[index]=nums[i];
            dfs(index+1,nums);
            vis[i]=0;  
        }
    }
};

