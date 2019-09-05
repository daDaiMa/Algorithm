
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)return true;
        ListNode*slow=head;
        ListNode*fast=head;
    
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode*cur=head;
        while(cur->next!=slow){
            ListNode*tmp=cur->next;
            cur->next=tmp->next;
            tmp->next=head;
            head=tmp;
        }
            
        if(fast)slow=slow->next;
        while(slow)
        {
            if(head->val!=slow->val)return false;
            head=head->next;
            slow=slow->next;
        }

        return true;
    }
};

