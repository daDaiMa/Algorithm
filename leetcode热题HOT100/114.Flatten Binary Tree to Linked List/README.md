# 114.Flatten Binary Tree to Linked List   
### 题目描述   
![image-20190814161518786](README.assets/image-20190814161518786.png)

### 解题思路

好奇怪 本地跑没问题 放leetcode上报错`AddressSanitizer: heap-use-after-free on address `这尼玛……

`TreeNode *dfs(TreeNode *root)` 传入一个树根，把这棵树撸成链表😂然后返回链表的尾巴

```cpp
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
```



妈呀 解决了

```cpp
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
```

![image-20190818181500259](README.assets/image-20190818181500259.png)

