
const MAX_INT = int(^uint(0) >> 1)
const MIN_INT = ^MAX_INT

func isValidBST(root *TreeNode) bool {
	return recursive(root, MIN_INT, MAX_INT)
}

func recursive(root *TreeNode, min, max int) bool {
	if root == nil {
		return true
	}
	if root.Val <= min || root.Val >= max {
		return false
	}
	return recursive(root.Left, min, root.Val) && recursive(root.Right, root.Val, max)
}
