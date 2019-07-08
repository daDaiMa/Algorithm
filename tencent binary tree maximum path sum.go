
var the_max int
const MAX_INT = int(^uint(0) >> 1)
const MIN_INT = ^MAX_INT

func maxPathSum(root *TreeNode) int {
    the_max=MIN_INT
	maxPathSumUtil(root)
	return the_max
}

func maxPathSumUtil(root *TreeNode) int {
	if root == nil {
		return 0
	}


	left := max(maxPathSumUtil(root.Left), 0)
	right := max(maxPathSumUtil(root.Right), 0)

	the_max = max(the_max, root.Val+left+right)

	return root.Val + max(left, right)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
