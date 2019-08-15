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
    ListNode* ans;
    ListNode* reverseList(ListNode* head) {
        recursion(head);
        return ans;
    }
    ListNode* recursion(ListNode* head) {
        if(!head)return NULL;       
        if(!head->next){
            ans=head;
            return head;
        }
        ListNode*tail=recursion(head->next);
        tail->next=head;
        head->next=NULL;
        return head;
    }
};
