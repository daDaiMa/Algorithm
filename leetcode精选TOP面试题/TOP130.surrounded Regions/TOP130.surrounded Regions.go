/*
  超出了时间限制 得优化 
  最后一个测试用例通不过
*/
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
		for j := 0; j < width; j++ {
			if board[i][j] == 'O' && !vis[i][j] && dfs(i, j) {
				paint(i, j)
			}
		}
	}
}

func paint(b, e int) {
	boards[b][e] = 'X'
	for i := 0; i < 4; i++ {
		if boards[b+dirx[i]][e+diry[i]] == 'O' {
			paint(b+dirx[i], e+diry[i])
		}
	}
}

func dfs(b, e int) bool {
	res := judge(b, e)
	if res == 0 {
		return false
	}
	if res == 2 {
		return true
	}
	boards[b][e] = 'X'
	for i := 0; i < 4; i++ {
		if boards[b+dirx[i]][e+diry[i]] == 'O' {
			if !dfs(b+dirx[i], e+diry[i]) {
				boards[b][e] = 'O'
				return false
			}
		}
	}
	boards[b][e] = 'O'
	return true
}

func judge(x, y int) int {
	// 0:处在边界 1:周围存在0 2:ok
	vis[x][y] = true
	if x+1 >= height || x-1 < 0 {
		return 0
	}
	if y+1 >= width || y-1 < 0 {
		return 0
	}
	if boards[x-1][y] == 'X' && boards[x+1][y] == 'X' && boards[x][y-1] == 'X' && boards[x][y+1] == 'X' {
		return 2
	}
	return 1
}
