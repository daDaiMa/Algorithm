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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* Head = new ListNode();
        Head->next=head;head=Head;
        ListNode* odd=head;
         while(true){
            if(odd->next&&odd->next-val%2)odd=odd.next;
            else break;
        }
        ListNode* n=odd->next;
        while(n){
            if(n.val%2==0){
                n=odd.next;
            }else{
                ListNode*tmp=n.next;
                n.next=odd.next;
                odd.next=n;
                odd=n;
                n=tmp;
            }
        }
        return head->next;
    }
};

