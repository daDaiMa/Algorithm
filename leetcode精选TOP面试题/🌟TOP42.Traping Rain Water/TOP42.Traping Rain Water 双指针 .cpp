class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int ans=0,lm=0,rm=0;
        while(left<right){
            if(height[left]>height[right]){
               rm=max(rm,height[right]);
               ans+=rm-height[right];
               right--;
            }else{
                lm=max(lm,height[left]);
                ans+=lm-height[left];
                left++;
            }
        }
        return ans;
    }
};
