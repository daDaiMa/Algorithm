
var boards [][]byte
var height int
var width int
var dirx = []int{-1, 1, 0, 0}
var diry = []int{0, 0, -1, 1}
var vis [][]bool

func solve(board [][]byte) {
	height = len(board)
	if height == 0 {
		return
	}
	width = len(board[0])
	if width == 0 {
		return
	}
	boards = board
	vis = make([][]bool, height)
	for i := 0; i < height; i++ {
		vis[i] = make([]bool, width)
	}
	for i := 0; i < height; i++ {
		if !vis[i][0] && board[i][0] == 'O' {
			dfs(i, 0)
		}
		if !vis[i][width-1] && board[i][width-1] == 'O' {
			dfs(i, width-1)
		}
	}
	for i := 0; i < width; i++ {
		if !vis[0][i] && board[0][i] == 'O' {
			dfs(0, i)
		}
		if !vis[height-1][i] && board[height-1][i] == 'O' {
			dfs(height-1, i)
		}
	}
	for i := 0; i < height; i++ {
		for j := 0; j < width; j++ {
			if board[i][j] == 'O' && !vis[i][j] {
				board[i][j] = 'X'
			}
		}
	}
}

func dfs(b, e int) {
	vis[b][e] = true
	for i := 0; i < 4; i++ {
		if judgeBorder(b+dirx[i], e+diry[i]) && boards[b+dirx[i]][e+diry[i]] == 'O' && !vis[b+dirx[i]][ e+diry[i]] {
			dfs(b+dirx[i], e+diry[i])
		}
	}
}

func judgeBorder(x, y int) bool {
	if x >= height || x < 0 {
		return false
	}
	if y >= width || y < 0 {
		return false
	}
	return true
}
