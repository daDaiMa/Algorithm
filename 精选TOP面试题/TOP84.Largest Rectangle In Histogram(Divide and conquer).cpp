class solution {
public:
    int largestrectanglearea(vector<int>& heights) {
        return largest(heights,0,heights.size());
    }
    int largest(vector<int>&heights,int start,int end){
        if(start==end)return 0;
        if(start+1==end)return heights[start]; 
        int min_index=0;
        for(int i=start;i<end;i++){
            if(heights[i]<heights[min_index])min_index=i;
        }
        return max(heights[min_index]*(end-start),largest(heights,start,min_index),largest(heights,min_index+1,end));
    }
};
