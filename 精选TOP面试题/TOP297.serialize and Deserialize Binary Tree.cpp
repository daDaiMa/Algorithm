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
        queue<TreeNode*>q;
        queue<TreeNode*>next;
        q.push(root);
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
                null=true;
            }
        }

        
        // 剔除末尾连续的null
        int i;
        for(i=ans.size()-1;i>=0&&(ans[i]<'0'||ans[i]>'9')&&ans[i]!='[';i--);
        ans=ans.substr(0,i+1);
        ans+="]";
        cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> nums(0);
        stringToVector(data,nums); 
        if(nums.size()==0)return NULL;
        return buildTree(nums,0);
    }

    TreeNode* buildTree(vector<int>&v,int index){
        if(v[index]==INT_MAX)return NULL;
        TreeNode*root=new TreeNode(v[index]);
        if(index*2+1<v.size())root->left=buildTree(v,index*2+1);
        if(index*2+2<v.size())root->right=buildTree(v,index*2+2);
        return root;
    }
    void stringToVector(string& input,vector<int>&ans){
        if(input.size()==2)return;// input=="[]"
        int num=0;
        char pre;
        int negative=1;
        for(char c:input){
            if(c=='['||c==']'||c=='u'||c=='l'){
                pre=c;
                continue;
            }
            if(c=='n'){
                ans.push_back(INT_MAX);
            }
            else if(c==','){
               if(pre!='l') ans.push_back(num*negative); 
               num=0;
               negative=1;
            }else if(c=='-'){
                negative=-1;
            }else{
                num*=10;
                num+=c-'0';
            }
            pre=c;
        }
        ans.push_back(num*negative);
        for(int n:ans){
            cout<<n<<",";
        }
        cout<<endl;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

