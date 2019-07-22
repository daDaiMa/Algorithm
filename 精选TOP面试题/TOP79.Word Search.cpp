/*
真的是日了狗了 提交有几个样例不通过，拿不通过的case放本地跑没问题。
放leetcode控制台跑也没问题 
*/

int dirx[4] = {-1, 1, 0, 0};
int diry[4] = {0, 0, -1, 1};
set<pair<int, int> > s;

bool dfs(vector<vector<char>> &board, int x, int y, string &word, int index) {
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())return false;
    if (board[x][y] == word[index++]) {
        if (index == word.length())return true;
        for (int i = 0; i < 4; i++) {
            auto pair = make_pair(x + dirx[i], y + diry[i]);
            if (s.count(pair))continue;
            s.insert(pair);
            if (dfs(board, x + dirx[i], y + diry[i], word, index))return true;
            s.erase(pair);
        }
        return false;
    }
    return false;
}

class Solution {
public:

    bool exist(vector<vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
