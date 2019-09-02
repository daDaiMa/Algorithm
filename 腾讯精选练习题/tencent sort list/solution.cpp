
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode**h=new ListNode*;
        ListNode**t=new ListNode*;

        quick_sort(h,t,head);    

        return *h;
    }
    
    void quick_sort(ListNode**h,ListNode**tail,ListNode*head){
        if(!head||!head->next){
            *h=head;
            *tail=head?head:NULL;
            return;
        }
        auto pivot=head;
        auto cur=head->next;
        auto front=head; 
        while(cur){
            if(cur->val<pivot->val){
                front->next=cur->next;
                cur->next=head;
                head=cur;
                cur=front->next;
            }else{
                front=cur;
                cur=cur->next;
            }
        }
        
        auto pivot_next=pivot->next;
        pivot->next=NULL;  
        quick_sort(h,tail,head);
        auto f_h=*h;
        auto f_t=*tail;
        
        quick_sort(h,tail,pivot_next);
        f_t->next=*h;
        *h=f_h;
    }
};
