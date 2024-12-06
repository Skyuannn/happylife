#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        nr = board.size();
        nc = board[0].size();
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }

private:
    int nr;
    int nc;
    bool dfs(vector<vector<char>> &board, string word, int i, int j, int x) {
        if (i < 0 || i >= nr || j < 0 || j >= nc || board[i][j] != word[x]) return false;
        if (x == word.size() - 1) return true;
        board[i][j] = '0';
        bool vec = dfs(board, word, i - 1, j, x + 1) || dfs(board, word, i + 1, j, x + 1) || dfs(board, word, i, j - 1, x + 1) || dfs(board, word, i, j + 1, x + 1);
        board[i][j] = word[x];
        return vec;
    }
};