class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int F[n][m];
        F[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            F[0][i] = F[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < n; ++i) {
            F[i][0] = F[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                F[i][j] = min(F[i - 1][j], F[i][j - 1]) + grid[i][j];
            }
        }
        
        return F[n - 1][m - 1]; 
    }
};
