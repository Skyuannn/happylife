#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void covered(vector<vector<int>> &matrix, int i, int j) {
        int nc = matrix.size();
        int nr = matrix[0].size();
        for (int m = 0; m < nr; m++) {
            matrix[i][m] = 0;
        }
        for (int n = 0; n < nc; n++) {
            matrix[n][j] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nc = matrix.size();
        int nr = matrix[0].size();
        vector<vector<int>> vec;
        for (int i = 0; i < nc; i++) {
            for (int j = 0; j < nr; j++) {
                if (matrix[i][j] == 0) {
                    vec.push_back({i, j});
                }
            }
        }
        for (int i = 0; i < vec.size(); i++) {
            covered(matrix, vec[i][0], vec[i][1]);
        }
    }
};