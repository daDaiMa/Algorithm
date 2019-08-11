struct trieTree {
    string word;
    trieTree *next[26];

    trieTree() {
        word = "";
        for (int i = 0; i < 26; i++)next[i] = NULL;
    }

    void insert(string &s) {
        auto cur = this;
        for (int i = 0; i < s.length(); i++) {
            if (!cur->next[s[i] - 'a'])cur->next[s[i] - 'a'] = new trieTree();
            cur = cur->next[s[i] - 'a'];
        }
        cur->word = s;
    }
};
class Solution {
public:
    vector<string> ans;

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        trieTree *root = new trieTree();
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        for (string &w:words)root->insert(w);
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++) {
                search(i, j, board[0].size(), board.size(), vis, root, board);
            }
        return ans;
    }

    void search(int i, int j, int m, int n, vector<vector<bool>> &vis, trieTree *root, vector<vector<char>> &board) {
        if (i < 0 || j < 0 || j >= m || i >= n || vis[i][j])return;

        root = root->next[board[i][j] - 'a'];
        if (root == NULL)return;
        if (root->word != ""){
            ans.push_back(root->word);
            root->word="";
        }
        vis[i][j] = true;
        search(i + 1, j, m, n, vis, root, board);
        search(i - 1, j, m, n, vis, root, board);
        search(i, j + 1, m, n, vis, root, board);
        search(i, j - 1, m, n, vis, root, board);
        vis[i][j] = false;
    }
};
