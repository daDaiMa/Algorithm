class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left;
        vector<int>right(height.size()+1);
        int _max=0;
        for(auto i:height){
            _max=max(_max,i);
            left.push_back(_max-i);
        }
        _max=0;
        for(int i=height.size()-1;i>=0;i--){
           _max=max(_max,height[i]);
          right[i]=_max-height[i]; 
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans+=min(right[i],left[i]);
        }
        return ans;
    }
};

