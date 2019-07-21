
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func build_Tree(tree []int, index int) *TreeNode {
	root := &TreeNode{tree[index], nil, nil}
	if index*2+1 < len(tree) {
		root.Left = build_Tree(tree, index*2+1)
	}
	if index*2+2 < len(tree) {
		root.Right = build_Tree(tree, index*2+2)
	}
	return root
}
