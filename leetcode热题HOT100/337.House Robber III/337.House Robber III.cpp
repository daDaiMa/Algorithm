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
    int rob(TreeNode* root){
        int wi,wo;
        robutil(root,wi,wo);
        return max(wi,wo);
    }
    void robutil(TreeNode* root,int&withroot,int&withoutroot) {
        if(!root){
            withroot=withoutroot=0;
            return; 
        }
        bool useleft,useright;

        int lw=0,lwo=0;
        int rw=0,rwo=0;
        
        robutil(root->left,lw,lwo);
        robutil(root->right,rw,rwo);
       
        withroot=root->val+lwo+rwo;
        withoutroot=max(lw,lwo)+max(rw,rwo);
        
    }
};


