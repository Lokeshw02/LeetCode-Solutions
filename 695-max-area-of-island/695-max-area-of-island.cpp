class Solution {
public:
    
    
    vector<vector<int>>dirs = {{1,0},{0,1},{-1,0},{0,-1}} ;
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int &count, int i, int j, int &n, int &m){
        visited[i][j] = true ;
        
        count++ ;
        
        //Go through the neighbours 
        
        for(auto &dir : dirs){
            int x = i + dir[0] ;
            int y = j + dir[1] ; 
            
            if(x >= 0 && y >=0 && x < n && y <m && grid[x][y] == 1 && !visited[x][y]){
                
                 
                 dfs(grid,visited,count,x,y,n,m)  ; 
                  
                
            }
               
        }
        
        
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
    
        vector<vector<bool>>visited(n,vector<bool>(m,false)) ;
        int count, res = 0 ;
        
        for(int i = 0; i< n ; i++){
            for(int j =0 ; j< m ;j++){
                
                if(!visited[i][j] && grid[i][j] == 1 ){
                    
                    count = 0 ;
                    dfs(grid,visited,count,i,j,n,m) ;
                    res = max(res,count) ;
                    
                }
            }
        }
       // return res == INT_MIN ? 0 : res ;
    return res ;
    }
};