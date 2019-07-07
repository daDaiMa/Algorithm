
func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}
	if len(lists) == 1 {
		return lists[0]
	}
	mid := len(lists) / 2
	one := mergeKLists(lists[:mid])
	another := mergeKLists(lists[mid:])

	if one == nil {
		return another
	}
	if another == nil {
		return one
	}

	var merge *ListNode
	var select_one *ListNode
	var tail *ListNode

	for {
		if one == nil && another == nil {
			break
		}
		if one != nil && (another == nil || another.Val > one.Val) {
			select_one = one
			one = one.Next
		} else {
			select_one = another
			another = another.Next
		}
		if merge == nil {
			merge = select_one
			tail = merge
		} else {
			tail.Next = select_one
			tail = tail.Next
		}
	}
	return merge
}
