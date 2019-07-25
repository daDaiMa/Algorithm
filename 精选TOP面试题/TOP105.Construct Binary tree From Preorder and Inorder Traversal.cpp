
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    }
    TreeNode* build(vector<int>&preorder, vector<int>& inorder,int pres,int pree,int ins,int ine){
        if(pree==pres){
            return  NULL;
        }
        if(pree-pres==1){
            return new TreeNode(preorder[pres]);
        }
        // 开始切分
        int split=ins+1;
        while(inorder[split]!=preorder[pres])split++;
        TreeNode*root=new TreeNode(preorder[pres]);
        root->left=build(preorder,inorder,pres+1,pres+1+split-ins,ins,split);
        root->right=build(preorder,inorder,pres+1+split-ins,pree,split+1,ine);
        return root;
    }
};
