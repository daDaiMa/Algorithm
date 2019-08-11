class Solution {
public:
    int numSquares(int n) {
        queue<int>q;
        q.push(0);
        int step=0;
        while(!q.empty()){
            int tmp=q.front();
            q.pop();
            step++;
            for(int i=sqrt(n-tmp);i>=1;i--){
                if(tmp+i*i==n){
                    return step;
                }
                q.push(temp+i*i);
            }
        }
    }
};


