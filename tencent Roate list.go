

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {

	if head == nil || head.Next == nil {
		return head
	}

	tail := head
	lenght := 1

	for tail.Next != nil {
		lenght++
		tail = tail.Next
	}

	k %= lenght

	tmp := head
	for i := 1; i < lenght-k; i++ {
		tmp = tmp.Next
	}

	tail.Next = head
	head = tmp.Next
	tmp.Next = nil
	
	return head
}
