
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(!intervals.size())return 0;
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[0]==b[0])return a[1]<b[1];
            return a[0]<b[0];
                });
        int ans=0;
        int end=intervals[0][0]-1;
        for(auto& seg:intervals){
            if(seg[0]>=end){
                end=seg[1];
            }else{
                //删掉自己或者前一个 看看谁的end更大
                //end大的占用空间 反正都是删一个 那就删掉占用空间多的
                end=min(end,seg[1]);
                ans++;
            }
        }
        return ans;
    }
};
