class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '.'));
        for(int i=1; i<m; i++){ //don't start from row 0 as we have to start the path from there
            for(int j=0; j<n-1; j++){ //also don't run loop till the last column as we have to end there
                grid[i][j] = '#';
            }
        }
        return grid;
    }
};