struct tree{
    int less_than;
    int value;
    int size;
    tree* left;
    tree* right;
    tree(int v){
        less_than=0;
        value=v;
        size=1;
        left=NULL;
        right=NULL;
    }
    int insert(int num){
        if(num==value){
            size++;
            return less_than;
        }
        else if(num>value){
            if(right)return less_than+size+right->insert(num);
            right=new tree(num);
            return less_than+size;
        }
        else{
            less_than++;
            if(left) return left->insert(num);
            left=new tree(num);
            return 0;
        }
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size()==0)return vector<int>{};
        tree*root=new tree(nums.back());
        vector<int>ans(nums.size(),0);
        for(int i=nums.size()-2;i>=0;i--){
            ans[i]=root->insert(nums[i]);
        }
        return ans;
    }
};

