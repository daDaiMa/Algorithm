
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
    int ans=0;
    int diameterOfBinaryTree(TreeNode* root) {
       deep(root);
        return max;
    }

    int deep(TreeNode*root){
        if(!root){
            return 0;
        }
        int left=deep(root->left);
        int right=deep(root->right);
        ans=max(ans,left+right);
        return max(right,left)+1;
    }
};
