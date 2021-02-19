#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> s(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i ++)
            for (int j = 1; j <= n; j ++)
                s[i][j] = matrix[i - 1][j - 1] - '0' + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        int mxlen = sqrt(s[m][n]);
        for (int len = mxlen; len >= 1; len --)
            for (int x2 = len; x2 <= m; x2 ++)
                for (int y2 = len; y2 <= n; y2 ++) {
                    int x1 = x2 - len + 1, y1 = y2 - len + 1;
                    if (check(x2, y2, x1, y1, len, s)) return len * len;
                }
        return 0;
    }

    bool check(int x2, int y2, int x1, int y1, int len, vector<vector<int>> &s) {
        int sum = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
        return sum == len * len;
    }
};

int main(void) {
    Solution solu;
    vector<vector<char>> matrix= {{'1', '0', '1', '0', '0'},
                        {'1', '0', '1', '1', '1'},
                        {'1', '1', '1', '1', '1'},
                        {'1', '0', '0', '1', '0'},
                        };
    cout << solu.maximalSquare(matrix) << endl;
    return 0;
}