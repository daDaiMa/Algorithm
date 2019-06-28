/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	if l2 == nil {
		return l1
	}
	if l1 == nil {
		return l2
	}

	i := l1
	c := 0 //进位
	for {
		if l2 == nil {
			return l1
		}

		i.Val += l2.Val + c

		c = 0

		if i.Val > 9 {
			i.Val %= 10
			c = 1
		}

		if i.Next == nil || l2.Next == nil {
			//如果没有i 了 而且有 l2 就要把 l2接到后边去 并且不要忘了进位
			if i.Next != nil {
				i.Next.Val += c
				c = 0
			}

			if l2.Next != nil {
				l2.Next.Val += c
				c = 0
			}
			break
		}

		i = i.Next
		l2 = l2.Next
	}

	if i.Next == nil && l2.Next == nil && c != 0 {
		i.Next = &ListNode{1, nil}
		c = 0
		return l1
	}

	if i.Next == nil && l2.Next != nil {
		l2 = l2.Next
		c = 0

		for {
			l2.Val += c
            c=0
			if l2.Val > 9 {
				c = 1
				l2.Val %= 10
			}
			i.Next = l2
			i = i.Next
			l2 = l2.Next
			if l2 == nil {
				if c != 0 {
					i.Next = &ListNode{1, nil}
					return l1
				}
				return l1
			}
		}

	} else {
		for i != nil {
			i.Val += c
            c=0
			if i.Val > 9 {
				c = 1
				i.Val %= 10
			}
			if i.Next == nil && c != 0 {
				i.Next = &ListNode{1, nil}
				break
			}
			i = i.Next
		}
	}

	return l1
}
