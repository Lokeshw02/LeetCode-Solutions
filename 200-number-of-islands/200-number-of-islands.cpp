class Solution {
public:
    
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}} ;
    
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        visited[row][col] = 1;
        
            
            // int dx[4] = {-1, 0, 1, 0};
            // int dy[4] = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
                    int nrow = row+dirs[i][0];
                    int ncol = col +dirs[i][1];
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                        dfs(nrow, ncol, visited, grid);
                    }
                }
            }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]  && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, visited, grid);
                }
            }
        }
        return count;
    }
};