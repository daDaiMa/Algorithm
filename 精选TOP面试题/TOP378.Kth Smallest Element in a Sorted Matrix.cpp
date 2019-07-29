class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low=matrix[0][0];
        int high=matrix.back().back();
        while(low<high){
            mid=(low+high)/2;
            int count=0;
            for(auto line:matrix){
                count+=upper_bound(line.begin(),line.end(),mid)-line.begin();
            }
            if(count>=k){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};

