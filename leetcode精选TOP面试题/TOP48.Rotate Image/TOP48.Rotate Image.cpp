
class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int i, j;
        for (i = 0; i < matrix.size(); i++) {
            for (j = 0; j < i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        for (i = 0; i < matrix.size(); i++) {
            int s = 0;
            int e = matrix[0].size() - 1;
            int tmp=0;
            while (s < e) {
                tmp = matrix[i][s];
                matrix[i][s] = matrix[i][e];
                matrix[i][e] = tmp;
                s++;
                e--;
            }
        }
    }
};
