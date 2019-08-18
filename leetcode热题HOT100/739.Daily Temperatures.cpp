
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // 维护一个非递增的栈
        
        stack<int>s;
        vector<int>ans(T.size(),0);
        for(int i=T.size()-1;i>=0;i--){
            while(!s.empty()&&T[s.top()]<=T[i])s.pop();
            if(!s.empty())ans[i]=s.top()-i;
            s.push(i);
        }
        return ans;
    }
};

