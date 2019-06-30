
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    
    if head==nil{
        return head
    }
    
	var pre *ListNode
	var cur *ListNode
	var next *ListNode

	var next_next *ListNode
	cur = head
	for {
		next = cur.Next

		if next == nil {
			cur.Next = pre
			head = cur
			return head
		}
    
        next_next = next.Next
		if next_next == nil {
			next.Next = cur
			cur.Next = pre
			head = next
			return head
		}
	//	next_next = next.Next

		next.Next = cur
		cur.Next = pre

		pre = next
		cur = next_next
	}
}
