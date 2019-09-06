

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size())return 0;
        int height=matrix.size();
        int width=matrix[0].size();
        bool* binary=new bool[width]();
        int ans=0;
        // new ➕ () 对空间进行初始化
        for(int i=0;i<width;i++)binary[i]=true;
        for(int h=0;h<height;h++){
            init(binary,width);
            for(int i=h;i<height;i++){
                for(int j=0;j<width;j++){
                    binary[j]&=(matrix[i][j]=='1'?true:false);
                }
                if(max_wight*(height-h+1)<ans)break;
                int max_wight=statistics(binary,width); 
                int area=max_wight*(i-h+1);
                ans=max(ans,area);
            }
        }
        return ans;
    }
    
    int statistics(bool*binary,int size){
        int ans=0;
        int cur=0;
        for(int i=0;i<size;i++){
            if(!binary[i]&&cur){
                ans=max(ans,cur); 
                cur=0;
                continue;
            }
            if(binary[i])cur++;
        }
        ans=max(ans,cur);
        return ans;
    }
    void init(bool*binary,int size){
        for(int i=0;i<size;i++)binary[i]=true;
    }
};
