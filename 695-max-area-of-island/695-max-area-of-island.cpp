class Solution {
public:
    
    
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}} ;
    
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>&grid, int &count ){
        visited[i][j] = true ;
        count ++ ;
        //Now visit the Neighbours 
        
        for(int t = 0; t<dirs.size(); t++){
            int x = i + dirs[t][0] ;
            int y = j + dirs[t][1] ;
            
            //x and y are 4 neighbours of i,j 
            
            if(x >=0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1 && !visited[x][y])
                dfs(x,y,visited,grid,count) ;
        }
    }
    
    
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int i, j, count = 0, res = 0 ;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(), false )) ;
        
        for(int i = 0; i < grid.size() ; i++){
            for(int j = 0; j < grid[0].size() ; j++){
                
                if(grid[i][j] == 1 && !visited[i][j] ){
                    count = 0 ;
                    dfs(i,j,visited,grid,count) ;
                    res = max(res,count) ;
                }
            }
        }
        
        return res ;
    }
};