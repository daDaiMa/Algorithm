class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const vector<int>&a,const vector<int>&b){
                if(a[0]>b[0])return true;
                if(a[0]==b[0])return a[1]<b[1];
                return false;
                });
        vector<vector<int>>ans(0);
        for(auto& p:people){
            if(p[1]>=ans.size())ans.push_back(p);
            else{
                ans.insert(ans.begin()+p[1],p);  
            }
        } 
        return ans;
    }
};
