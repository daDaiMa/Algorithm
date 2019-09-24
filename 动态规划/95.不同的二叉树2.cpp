#include <bits/stdc++.h> 

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>res;
        if(n==0){
            return res;
        }
        return util(1,n);
    }
    vector<TreeNode*> util(int start,int end){
        vector<TreeNode*>list;
        if (start>end){
            list.push_back(NULL);
        }
        
        for(int i=start;i<=end;i++){
            auto left=util(start,i-1);
            auto right=util(i+1,end);
            for(auto l:left)
                for(auto r:right){
                    TreeNode*root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    list.push_back(root);
                }
        }
        
        return list;
    }
};
