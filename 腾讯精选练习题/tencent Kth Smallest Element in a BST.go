var current int
var ans int

func kthSmallest(root *TreeNode, k int) int {
	mid_order(root, k)
    current=0
	return ans
}

func mid_order(root *TreeNode, k int) {

    if current > k{
        return 
    }
    
	if root.Left != nil {
		mid_order(root.Left, k)
	}

	current++
	if current == k {
		ans = root.Val
		return
	}
    
    if current>k{
        return
    }

	if root.Right != nil {
		mid_order(root.Right, k)
	}
}
