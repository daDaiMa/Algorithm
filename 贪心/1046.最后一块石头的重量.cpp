
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(auto s:stones){
            q.push(s);
        }
        while(1){
            int a=q.top();q.pop();
            if(q.empty())return a;
            int b=q.top();q.pop();
            q.push(abs(a-b)); 
        }
    }
};
