class Solution {
public:
    
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}} ;
    
   void dfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& image, int color, int temp_color){
       
       visited[i][j] = true ;
       
       for(int t = 0; t < dirs.size() ; t++){
            int x = i + dirs[t][0] ;
            int y = j + dirs[t][1] ;
            
            if( x < image.size()  && x >= 0 && y < image[0].size() && y >= 0 &&  !visited[x][y] && image[x][y] == temp_color){
                image[x][y] = color ;
           
                dfs(x,y,visited,image,color,temp_color) ;
           
            }
        }
       
       
   }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       
       vector<vector<int>> visited(image.size(),vector<int>(image[0].size(), false)) ;
        
        int temp_color = image[sr][sc] ;
        image[sr][sc] = color ;
        
        
        
       dfs(sr,sc,visited,image,color,temp_color ) ;
        
       return image ;
        
        
    }
};