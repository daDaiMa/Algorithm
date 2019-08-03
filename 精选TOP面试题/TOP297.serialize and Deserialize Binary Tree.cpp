/**
    通过47/48 卡在了最后一个case 超出时间限制
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
        queue<TreeNode*>q;
        queue<TreeNode*>next;
        bool null=true;
        string ans="[";
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            if(tmp==NULL)ans+="null,";
            else ans+=to_string(tmp->val)+",";
            if(!tmp){
                next.push(NULL);
                next.push(NULL);
            }else{
                next.push(tmp->left);
                next.push(tmp->right);
                if(tmp->left!=NULL||tmp->right!=NULL)null=false;
            }
            if(q.empty()&&!null){
                swap(q,next);
            }
        }
        ans[ans.size()-1]=']';
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        nums=stringToVector(data);                
        return buildTree(nums,0);
    }

    TreeNode* buildTree(vector<int>&v,int index){
        if(v[index]==INT_MAX)return NULL;
        TreeNode*root=new TreeNode(v[index]);
        if(index*2+1<v.size())root->left=buildtree(v,index*2+1);
        if(index*2+2<v.size())root->right=buildtree(v,index*2+2);
        return root;
    }
    vector<int> stringToVector(string input){
        vecotr<int>ans;
        if(input.size()==2)return ans;// input=="[]"
        int num=0;
        for(char c:input){
            if(c=='['||c==']'||c=='u'||c=='l')continue;
            if(c=='n')ans.push_back(INT_MAX); 
            else if(c==','){
               ans.push_back(num); 
               num=0;
            }else{
                num*=10;
                num+=c-'0';
            }
        }
        ans.push_back(num);
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

