
/**
 * Definition for TreeNode.
 * type TreeNode struct {
 *     Val int
 *     Left *ListNode
 *     Right *ListNode
 * }
 */
 func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
     min:=p.Val
     max:=q.Val
     if min>q.Val{
         min=q.Val
         max=p.Val
     }
     if root.Val<min{
         return lowestCommonAncestor(root.Right,p,q)
     }
     if root.Val>max{
         return lowestCommonAncestor(root.Left,p,q)
     }
     return root
}

