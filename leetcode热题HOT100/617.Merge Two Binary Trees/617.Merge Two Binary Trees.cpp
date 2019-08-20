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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1&&!t2)return NULL;
        if(t1==NULL^t2==NULL)return t1?t1:t2;
        TreeNode*root=t1;
        
        root->val=getVal(t1)+getVal(t2);
        if(t1->left&&t2->left)root->left=mergeTrees(t1->left,t2->left);
        else root->left=t1->left?t1->left:t2->left;
        if(t1->right&&t2->right)root->right=mergeTrees(t1->right,t2->right);
        else root->right=t1->right?t1->right:t2->right;
        return root;
    }
    int getVal(TreeNode*root){
        if(!root)return 0;
        return root->val;
    }
};

