#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        dfs(root);
    }

    TreeNode *dfs(TreeNode *root) {
        if (!root)return NULL;

        TreeNode *ltail = dfs(root->left);
        TreeNode *rtail = dfs(root->right);

        if (!ltail && !rtail)return root;
        if (!ltail && rtail)return rtail;
        if (!rtail && ltail) {
            root->right = root->left;
            return ltail;
        }

        TreeNode *right = root->right;
        root->right = root->left;
        ltail->right = right;

        return rtail;
    }
};


int main() {
    Solution s;
    vector<int> c{2};

    TreeNode*root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right=new TreeNode(5);
    root->right->right=new TreeNode(6);

    s.flatten(root);
    while(root){
        cout<<root->val<<endl;
        root=root->right;
    }
    return 0;
}

