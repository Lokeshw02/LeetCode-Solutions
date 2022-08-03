class Solution {
public:
    
    vector<vector<int>>dirs = {{0,1},{1,0},{-1,0},{0,-1}} ;
    
    void dfs(int i, int j, vector<vector<bool>>&visited, vector<vector<char>>& board){
        
        if(i<0 || i>= board.size() || j<0 || j>= board[0].size()) 
            return ;
        if(board[i][j] == 'X' || visited[i][j]) return ;
        
        visited[i][j] = true ;
        
        for(int t= 0; t < dirs.size(); t++){
            int x = i + dirs[t][0] ;
            int y = j + dirs[t][1] ;
            
            dfs(x,y,visited,board) ;
        }
    }
    
    
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false)) ;
        
        
      if(board.size() == 0 ) return ; 
                                   
                                   //Do a DFS from boundary 
       
         for(int i = 0; i < board.size(); i++){
             //Left
             dfs(i,0,visited,board) ;
             //Rigth 
             dfs(i,board[0].size()-1,visited, board) ;
             
         }
         //Top and Bottom 
                                  
         for(int j = 0; j < board[0].size(); j++){
             //top 
             dfs(0,j,visited,board) ;
             //Bottom 
             dfs(board.size()-1,j,visited, board) ;
             
         } 
                                   
         //Flip the Unvisited 0 
        for(int i = 0; i< board.size(); i++){
            for(int j = 0 ;j< board[0].size(); j++){
                
                if(board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X' ;
            }
        }                           

 
                                   
                                 
      
                                   
                            
    }
};