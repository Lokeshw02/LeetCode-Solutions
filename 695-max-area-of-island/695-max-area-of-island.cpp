class Solution {
public:
    
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0} } ;
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>&dp, int i, int j, int &count , int &n, int &m){
        
        dp[i][j] = true ;
        count++ ;
        
        for(auto & dir : dirs){
            int x = i + dir[0] ;
            int y = j + dir[1] ;
            
            if(x < n && x >= 0 && y < m && y >= 0 && !dp[x][y] && grid[x][y]) 
                dfs(grid,dp,x,y,count,n,m) ;
            
        }
        
        
       
    }
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<bool>>dp(n, vector<bool>(m,false)) ;
        
        int count, res = 0 ;
        
        for(int i = 0 ; i<n ; i++){
            for(int j = 0; j< m ; j++){
                if(!dp[i][j] && grid[i][j]){
                     count = 0 ;
                     dfs(grid,dp,i,j,count,n,m);
                     res = max(res,count) ;
                }
                 
            }
        }
    
     
    return res ;
    }
};