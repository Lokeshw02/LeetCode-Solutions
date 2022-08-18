class Solution {
public:
    
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}} ;
    
    
    int sideAdder(int i, int j, vector<vector<int>>& grid, int n, int m ){
        
        int sides = 0 ;
        
        for(auto &dir : dirs){
            int x = i + dir[0] ;
            int y = j + dir[1] ;
            
            if(x < grid.size()  && x >= 0 && y < grid[0].size() && y >= 0 && grid[x][y] == 0 || x == -1 || x == n || y == m || y == -1 ) 
                sides++ ;
                
        }
        
        return sides ;
      
    }
 int islandPerimeter(vector<vector<int>>& grid) {
        
        int res = 0;
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        for(int i=0; i< grid.size(); i++){
            for(int j = 0; j<grid[0].size() ; j++){
                if(grid[i][j] == 1)
                  res += sideAdder(i,j,grid,n,m) ;  
            }
        }
        
        return res ;
        
    }
};