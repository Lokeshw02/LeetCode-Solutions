class Solution {
public:
    
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}} ;
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>&visited, int i, int j, int n, int m){
        
        visited[i][j]  = true ;
        
        // Go through neigbours 
        
        for(auto dir : dirs){
            int x = i + dir[0] ;
            int  y = j + dir[1] ;
            
            if(x >= 0 && y >= 0 && x < n && y < m && !visited[x][y] && grid[x][y] == '1' )
                dfs(grid, visited, x, y, n, m) ;
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        vector<vector<bool>>visited(n,vector<bool>(m,false)) ;
        int count = 0 ;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j< m ; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, visited, i, j, n, m) ;
                    count++ ;
                }
            }
        }
        return count ;
    }
};