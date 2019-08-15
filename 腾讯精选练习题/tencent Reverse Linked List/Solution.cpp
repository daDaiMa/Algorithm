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
    ListNode* reverseList(ListNode* head) {
        if(!head)return NULL;
        ListNode* front=NULL;
        ListNode* cur=head;
        ListNode* next=head->next;
        while(next){
            cur->next=front;
            front=cur;
            cur=next;
            next=next->next;
        }
        cur->next=front;
        return cur;
    }
};

