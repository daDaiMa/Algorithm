
func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	curr := head.Next

	curr_pre := head
	for {
		if curr == nil {
			return head
		}

		var pre *ListNode
		pre = nil

		index := head

		for {
			if index.Val < curr.Val {
				pre = index
				index = index.Next
				if index == curr {
					curr_pre = curr
					curr = curr.Next
					break
				}
			} else {
				if pre == nil {
					//链表换头
					curr_pre.Next = curr.Next
					curr.Next = head
					head = curr
					curr = curr_pre.Next
					break
				} else {
					curr_pre.Next = curr.Next
					curr.Next = pre.Next
					pre.Next = curr
					curr = curr_pre.Next
					//curr_pre = 
                    break
				}
			}
		}
	}
}
