class Solution {
public:
    
      vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}} ; 
    
   void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2,  vector<vector<bool>> &visited, int n, int m , int &count){
        
        visited[i][j] = true ;
       

        
        for(auto &dir : dirs){
            int x = i + dir[0] ;
            int y = j + dir[1] ;
            
             if(x >=0 && x < n && y >= 0 && y < m  ){
                 if(grid1[x][y] == 0 && grid2[x][y] == 1) {
                 count = 0 ;
                  visited[i][j] = false ;
                  return ;
                 }
                
             }
                
            if(x >=0 && x < n && y >= 0 && y < m && !visited[x][y] && grid1[x][y] && grid2[x][y] ) 
                dfs(x,y,grid1,grid2,visited,n,m,count) ;
        }
    }
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int n = grid1.size() ;
        int m = grid1[0].size() ;
        int count, res = 0 ;
        vector<vector<bool>> visited(n,vector<bool>(m,false) ) ;
        
        for(int i = 0; i< n ; i++){
            for(int j = 0; j< m ; j++){
                
                if(!visited[i][j] && grid2[i][j] == 1 && grid1[i][j] == 1){
                      count = 1 ;
                      dfs(i,j,grid1,grid2,visited,n,m,count) ;
                      res += count ;
                }
                  
            }
        }
        
        return res ;
    }
};