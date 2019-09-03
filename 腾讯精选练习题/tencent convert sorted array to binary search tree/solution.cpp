
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,0,nums.size());
    }
    TreeNode* build(vector<int>&nums,int s,int e){
        if(s>=e)return NULL;
        if(s==e-1)return new TreeNode(nums[s]);
        int mid=(s+e)/2;    
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=build(nums,s,mid);
        root->right=build(nums,mid+1,e);
        return root;
    }
};
