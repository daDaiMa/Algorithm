
var ans = make([]int, 0)

func inorderTraversal(root *TreeNode) []int {
	ans = make([]int, 0)
	inorderTraversalUtil(root)
	return ans
}

func inorderTraversalUtil(root *TreeNode) {
	if root == nil {
		return
	}
	inorderTraversalUtil(root.Left)
	ans = append(ans, root.Val)
	inorderTraversalUtil(root.Right)
}
