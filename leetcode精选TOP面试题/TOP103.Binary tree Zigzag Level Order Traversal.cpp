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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>cur;
        queue<TreeNode*>next;
        cur.push(root);
        vector<vector<int>>ans;
        ans.push_back(vector<int>{root->val})
        bool odd=false;
        vector<int>v;
        while(!cur.empty()){
            TreeNode* temp = cur.front();cur.pop();
            if(temp->left){
                next.push(temp->left);
                v.push_back(temp->left->val);
            }if(temp->right){
                next.push(temp->right);
                v.push_back(temp->right->val);
            }if(cur.empty()){
                swap(cur,next);
                odd=!odd;
                if(odd){
                    int i=0;
                    int j=v.size()-1;
                    while(i<j){
                        int t=v[i];
                        v[i]=v[j];
                        v[j]=t;
                        i++;
                        j--;
                    }
                }
                ans.push_back(v);
                v.clear();
            }
        }
        return ans;
    }
};

