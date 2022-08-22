class Solution {
public:
    
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}} ; 
   
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int sr, int sc, int &color, int &curr_color, int n, int m){
        
       // if(grid[sr][sc] = curr_color)
            grid[sr][sc] = color ;
            visited[sr][sc] = true ;
        
        for(auto &dir : dirs){
         int x = sr + dir[0] ;
         int y = sc + dir[1] ; 
            
        if(x >=0 && x < n && y >= 0 && y < m && grid[x][y] == curr_color && !visited[x][y] ) 
            dfs(grid, visited, x,y,color,curr_color,n,m) ;
        }
        
        
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size() ;
        int m = image[0].size() ;
        
       vector<vector<bool>> visited(n,vector<bool>(m,false)) ;
        
        int curr_color = image[sr][sc] ;
        
        dfs(image, visited, sr,sc,color,curr_color, n, m ) ;
        
        return image ;
    }
};