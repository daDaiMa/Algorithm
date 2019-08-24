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
    TreeNode* convertBST(TreeNode* root) {
        if(root)
            count(root,0); 
        return root;
    }
    int count(TreeNode*root,int add){
        if(!root)return 0;
        int sum=count(root->right);
        int tmp=sum;
        sum+=root->val;
        sum+=count(root->left,add+sum);
        root->val+=tmp+add;
        return sum;
    }
};
