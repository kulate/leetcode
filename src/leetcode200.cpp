#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int cnt = 0;
    int find(vector<int> &p, int idx) {
        if (p[idx] != idx) p[idx] = find(p, p[idx]);
        return idx;
    }
    void merge(vector<int> &p, int idx1, int idx2) {
        int x = find(p, idx1), y = find(p, idx2);
        if (x != y) cnt --;
        p[x] = y;
    }
    int numIslands(vector<vector<string>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
        vector<int> p(m * n, -1);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                int idx = i * m + j;
                if (grid[i][j] == "1") cnt++, p[idx] = idx;
            }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == "0") continue;
                grid[i][j] = "0";
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == "1") {
                        int idx1 = i * m + j, idx2 = ni * m + nj;
                        merge(p, idx1, idx2);
                    }
                }
            }
        } 
    return cnt;
    }
};

int main(void) {
    vector<vector<string>> grid = {{"1","1","1"},{"1","1","0"},{"1","1","0"}};
    Solution solu;
    cout << solu.numIslands(grid) << endl;
    return 0;
}