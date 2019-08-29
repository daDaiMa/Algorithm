class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int front=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                front=i-1;
                break;
            }
        }

        if(front==-1){
            sort(nums.begin(),nums.end());
            return;
        }

        bool change=false;
        for(int i=front+2;i<nums.size();i++){
            if(nums[i]<=nums[front]){
                swap(nums[i-1],nums[front]);
                change=true;
                break;
            }
        }

        if(!change){
            swap(nums[front],nums[nums.size()-1]);
        }

        int i=front+1;
        int j=nums.size()-1;
        for(;i<=j;){
            swap(nums[i],nums[j]);
            i++;j--;
        }

    }
};



