package main

func numTrees(n int) int {
	if n <= 1 {
		return 1
	}

	/*

		G(n)=长度为n的序列不同的二叉树搜索个数
		F(i,n)=以i为根不同的二叉树搜索树的个数

		G(0)=G(1)=1

		G(n)=F(1,n)+F(2,n)+F(3,n)+...F(n,n)

		F(i,n)=G(i-1)*G(n-i)
	*/

	G := make([]int, n+1)
	G[0] = 1
	G[1] = 1

	for i := 2; i <= n; i++ {
		for j := 1; j <= i; j++ {
			G[i] += G[j-1] * G[i-j]
		}
	}

	return G[n]
}
