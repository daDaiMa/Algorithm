
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
    void flatten(TreeNode* root) {
        if(!root)return;
        flat(root);
    }
    // 把根为root的二叉树展开成链表right 并且返回最后一个叶子节点
    // 函数假设输入的root不为空
    TreeNode* flat(TreeNode* root){
        auto left=root->left;
        auto right=root->right;

        clear(root);

        if(left){
            root->right=left;
            root=flat(left);
        }
        if(right){
            root->right=right;
            root=flat(right);
        }
        return root;
    }
    void clear(TreeNode* root){
        root->right=NULL;
        root->left=NULL;
    }
};

