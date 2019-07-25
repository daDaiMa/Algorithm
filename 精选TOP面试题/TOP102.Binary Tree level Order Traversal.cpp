
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        queue<TreeNode*>next;
        vector<vector<int>>ans;
        if(!root){
            return nil
        }
        vector<int>curr;
        q.push(root);
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            curr.push_back(tmp->val);
            if(tmp->left)next.push(tmp->left);
            if(tmp->right)next.push(tmp->right);
            if(q.empty()){
                swap(q,next);
                ans.push_back(curr);
                while(curr.size()){
                    curr.pop_back();
                }
            }
        }
        return ans;
    }
};
