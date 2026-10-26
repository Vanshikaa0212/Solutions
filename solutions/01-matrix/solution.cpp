
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        queue<pair<int,int>> q;

        vector<vector<int>> dist(r, vector<int>(c, -1));

        vector<pair<int,int>> d = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        // Add all zero cells to the queue
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(auto [dx,dy] : d){
                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && nx < r && ny >= 0 && ny < c && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }

        return dist;
    }
};
