// TL 95/96
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        for(int i=0;i<heights.size();i++){
            int _min=heights[i]; 
            for(int j=i;j<heights.size();j++){
               _min=min(_min,heights[j]);
               ans=max(ans,(j-i+1)*_min);
            }
        }
        return ans;
    }
};
