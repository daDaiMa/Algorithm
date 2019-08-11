/**
  47/48 最后一个case没通过
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="[";
        TreeToString(root,ans); 
        ans[ans.length()-1]=']';
        return ans;
    }
    void TreeToString(TreeNode*root,string&out){
        if(root==NULL){
            out+="null,";
            return;
        }
        out+=to_string(root->val)+",";
        TreeToString(root->left,out);
        TreeToString(root->right,out);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index=0;
        return buildTree(data,index);
    }

    TreeNode* buildTree(string&input,int&index){
        int num=Read(input,index);
        if(num==INT_MAX){
            return NULL;    
        }
        TreeNode*root=new TreeNode(num);
        root->left=buildTree(input,index);
        root->right=buildTree(input,index);
        return root;
    }
    int Read(string&input,int& index){
        int ans=0;
        int sign=1;
        for(int i=index;i<input.length();i++){
             if(input[i]=='[')continue; 
             if(input[i]=='n'){
                i+=5;
                index=i;
                return INT_MAX;
             } 
             if(input[i]=='-'){
                sign=-1;
                continue;
             }
             if(input[i]==','||input[i]==']'){
                index=i+1;
                return ans*sign;
             }
             ans*=10;
             ans+=input[i]-'0';
        }
        return INT_MAX;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

