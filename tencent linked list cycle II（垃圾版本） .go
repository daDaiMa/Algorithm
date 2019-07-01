

func detectCycle(head *ListNode) *ListNode {

	if head == nil {
		return nil
	}

	node_set := make(map[*ListNode]bool)

	tmp := head
	//index := 0

	for {
		if tmp.Next == nil {
			return nil
		}
		if _, ok := node_set[tmp]; ok {
			return tmp
		}else{
			node_set[tmp]=true
            tmp = tmp.Next
		}
	}
	
}
