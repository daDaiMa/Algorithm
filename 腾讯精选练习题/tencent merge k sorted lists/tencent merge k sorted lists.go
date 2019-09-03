
func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}
	if len(lists) == 1 {
		return lists[0]
	}

	var ans *ListNode
	var cur *ListNode
	var cur_min *ListNode
	var select_index int

	for {
		cur_min = nil
		all_nil := true
		for i := 0; i < len(lists); i++ {
			if lists[i] == nil {
				continue
			}
			all_nil = false
			if cur_min == nil || cur_min.Val > lists[i].Val {
				cur_min = lists[i]
				select_index = i
			}
		}
		if all_nil {
			break
		}

		if ans == nil {
			ans = cur_min
			cur = ans
		} else {
			cur.Next = cur_min
			cur = cur.Next
		}

		lists[select_index] = lists[select_index].Next

	}
	return ans
}
