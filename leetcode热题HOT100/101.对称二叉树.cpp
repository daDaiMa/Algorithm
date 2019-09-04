
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
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return same(root->left,root->right);
    }
    bool same(TreeNode*left,TreeNode*right){
        if(!left&&!right)return true;
        if(!left||!right)return false;
        return left->val==right->val&&same(left->left,right->right)&&same(left->right,right->left);
    }
};
