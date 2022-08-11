class Solution {
public:
    
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}} ;
    
    
    void dfs(int i, int j,vector<vector<char>>& grid, vector<vector<bool>>& visited){
        
        visited[i][j] = true ;
        int n  = grid.size() ;
        int m = grid[0].size() ;
        
        for(int t = 0 ; t< dirs.size(); t++){
            int x = i + dirs[t][0] ;
            int y = j + dirs[t][1] ;
            
          if(x >= 0 && x < n && y < m && y >=0 && grid[x][y] == '1' && !visited[x][y])
             dfs(x,y,grid,visited) ;
            
           
        }
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        int count = 0 ;
      
        vector<vector<bool>> visited(n, vector<bool>(m,false)) ;
        
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(!visited[i][j] && grid[i][j] == '1'){
                   
                    dfs(i,j,grid,visited) ;
                     count++ ;
                }
                    
            }
        }
        
    
       return count ;
       
    }
};