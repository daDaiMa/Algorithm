
func lowestCommonAncestor(root, q, p *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	r_find_q, r_find_p := find(root.Right, q, p)

	if root == q && r_find_p {
		return root
	}
	if root == p && r_find_q {
		return root
	}

	if r_find_p && r_find_q {
		if root.Right == p {
			return p
		}
		if root.Left == q {
			return q
		}
		return lowestCommonAncestor(root.Right, q, p)
	}

	l_find_q, l_find_p := find(root.Left, q, p)
	if root == q && l_find_p {
		return root
	}
	if root == p && l_find_q {
		return root
	}

	if l_find_p && l_find_q {
		if root.Right == p {
			return p
		}
		if root.Left == q {
			return q
		}
		return lowestCommonAncestor(root.Left, q, p)
	}

	if l_find_p && r_find_q || l_find_q && r_find_p {
		return root
	}

	return nil
}

func find(root, q *TreeNode, p *TreeNode) (bool, bool) {
	if root == nil {
		return false, false
	}
	//if root == q {
	//	return root == q, root == p
	//}
	l1, l2 := find(root.Left, q, p)
	r_1, r_2 := find(root.Right, q, p)
	return l1 || r_1 || root == q, l2 || r_2 || root == p
}
