
class Solution {
public:

    void dfs(int i, int j, vector<vector<bool>>& vis,
             vector<vector<int>>& grid, int n, int m, long long& sum) {

        if(i < 0 || j < 0 || i >= n || j >= m ||
           vis[i][j] || grid[i][j] == 0)
            return;

        vis[i][j] = true;
        sum += grid[i][j];

        dfs(i - 1, j, vis, grid, n, m, sum);
        dfs(i + 1, j, vis, grid, n, m, sum);
        dfs(i, j - 1, vis, grid, n, m, sum);
        dfs(i, j + 1, vis, grid, n, m, sum);
    }

    int countIslands(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int islands = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] > 0 && !vis[i][j]) {

                    long long sum = 0;

                    dfs(i, j, vis, grid, n, m, sum);

                    if(sum % k == 0) {
                        islands++;
                    }
                }
            }
        }

        return islands;
    }
};
