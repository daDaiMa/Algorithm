
class Solution {
public:

    std::map<Node *, Node *> m;

    Node *copyRandomList(Node *head) {
        return copyNode(head);
    }

     Node *copyNode(Node *node) {
         if(node==NULL){
             return NULL;
         }
        Node *copy = new Node(node->val, node->next, node->random);
        this->m[node] = copy;
        std::cout << m.size() << "==" << m[node] << std::endl;
        if (copy->next != NULL) {
            if (this->m[node->next] != NULL) {
                std::cout << "map::" << m[node->next] << std::endl;
                copy->next = this->m[node->next];
            } else copy->next = copyNode(copy->next);
        }
        if (copy->random != NULL) {
            if (this->m[node->random] != NULL) {
                copy->random = this->m[copy->random];
            } else copy->random = copyNode(copy->random);
        }
        return copy;
    }
};
