
class Solution {
public:
    Node *connect(Node *root) {
        if(root==NULL){
            return NULL;
        }
        queue<Node *> q;
        queue<Node *> next;
        q.push(root);
        while (!q.empty()) {
            auto head = q.front();
            q.pop();
            if (q.empty())head->next = NULL;
            else head->next = q.front();
            if (head->left)next.push(head->left);
            if (head->right)next.push(head->right);
            if (q.empty()) {
                swap(q, next);
            }
        }
        return root;
    }
};
