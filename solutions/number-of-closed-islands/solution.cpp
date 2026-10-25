
class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis,
             int i, int j, int n, int m, bool &isClosed) {

        if (i < 0 || j < 0 || i >= n || j >= m ) {
            isClosed = false;
            return;
        }

        if (vis[i][j] || grid[i][j] != 0)
            return;

        vis[i][j] = true;

        dfs(grid, vis, i - 1, j, n, m, isClosed);
        dfs(grid, vis, i + 1, j, n, m, isClosed);
        dfs(grid, vis, i, j - 1, n, m, isClosed);
        dfs(grid, vis, i, j + 1, n, m, isClosed);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int island = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    bool isClosed = true;

                    dfs(grid, vis, i, j, n, m, isClosed);

                    if (isClosed)
                        island++;
                }
            }
        }

        return island;
    }
};
