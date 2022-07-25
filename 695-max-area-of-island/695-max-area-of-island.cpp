class Solution {
public:
    vector<vector<int>>dirs = {{1,0},{0,1},{-1,0},{0,-1}} ;
    
    bool isValidX(int x, int m){
        return (x>=0 && x<m) ;
    }
    
     bool isValidY(int y, int n){
        return (y>=0 && y<n) ;
    }
    
    bool isValidCell(int x, int y, int m, int n){
     
        return isValidY(y,n) && isValidX(x,m) ;
    
    }
    
    bool isValidNode(int x, int y, vector<vector<int>>& grid){
        return isValidCell(x,y,grid.size(),grid[0].size()) && grid[x][y] ;
    }
    
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& grid, int &count ){
      
    visited[i][j] = true ;
    count ++ ;
    //Now visit the neighbors 
    
    for(int t = 0 ; t < dirs.size() ; t++){
        
        int x = i + dirs[t][0] ;
        int y = j + dirs[t][1] ;
        
        //x and y are the neighbors of i,j 
        //Chek if it is a node 
        
        if(isValidNode(x,y,grid) && !visited[x][y]) 
            dfs(x,y,visited,grid,count) ;
        

    }
        
    
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int i,j, count = 0 , res =  0 ;
        vector<vector<bool>>visited(grid.size(), vector<bool>(grid[0].size(), false)) ;
        
        for(int i = 0 ; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                
                if(grid[i][j] == 1 && !visited[i][j]){
                    count = 0 ;
                    dfs(i,j,visited,grid,count) ; 
                    res = max(res, count) ;
                }
            }
        }
        
        return res ;
    }
};