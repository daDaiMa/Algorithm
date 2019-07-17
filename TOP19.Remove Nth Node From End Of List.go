
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	ptr1 := head
	ptr2 := head

	for i := 0; i < n; i++ {
		if ptr2.Next == nil {
			return head.Next
		}
		ptr2 = ptr2.Next
	}

	for ptr2.Next != nil {
		ptr2 = ptr2.Next
		ptr1 = ptr1.Next
	}

	ptr1.Next = ptr1.Next.Next
	return head
}
