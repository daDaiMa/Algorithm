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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans;
        solve(root,ans);
        return ans;
    }
    int solve(TreeNode*root,int&themax){
        if(!root){
            themax=0;
            return 0;
        } 
        
        int left_max,right_max;
        int left_ans,right_ans;
        left_max=solve(root->left,left_ans);
        right_max=solve(root->right,right_ans);

        themax=max(left_ans,right_ans);
        themax=max(themax,left_max+right_max);
        themax=max()
        return max(left_max,right_max)+1;

    }
};
