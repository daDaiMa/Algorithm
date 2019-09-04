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
    int pathSum(TreeNode* root, int sum) {
        if(!root)return 0;
        return util(root, sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
    int util(TreeNode* root,int sum){
        if(!root)return 0;
        sum-=root->val;
        return util(root->left, sum)+util(root->right,sum)+(sum==0?1:0);
        // 这个括号带上 ……坑死了
    }
};


