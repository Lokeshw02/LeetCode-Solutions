class Solution {
public:
    
   vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}} ;
    
    void dfs(int i, int j,vector<vector<bool>> &visited,vector<vector<char>>& board){
        
        if(i<0 || i>= board.size() || j<0 || j>=board[0].size())   return ;
          
        if(board[i][j] == 'X' || visited[i][j]) return ;
        
        visited[i][j] = true ;
        
         for(int t = 0 ; t<dir.size(); t++){
             int x = i + dir[t][0] ;
             int y = j + dir[t][1] ;
             
             dfs(x,y,visited,board) ;
             
         }
        
    }
    
    void solve(vector<vector<char>>& board) {
     if(board.size() == 0 ) return ;
     
  
    vector<vector<bool>>visited (board.size(), vector<bool>(board[0].size(),false)) ;
        
        //Do a dfs from boundary 
        //Top and Bottom Boundary 
        
        for(int i = 0; i <board[0].size(); i++){
            //Top Boundary 
            dfs(0,i,visited,board) ;
            //Bottom Boundary 
            dfs(board.size()-1,i,visited,board) ;
        }
        
        //Left and Right Boundaries 
        
        for(int j = 0; j < board.size();j++){
            //Left 
            dfs(j,0,visited,board) ; 
            //Right 
            dfs(j,board[0].size()-1,visited,board) ;
            
            }
            
            //Flip the Unvisited O 
            
            for(int i = 0 ; i< board.size(); i++){
                for(int j = 0 ; j< board[0].size(); j++){
                    if( (board[i][j] == 'O') && !visited[i][j] )
                        board[i][j] = 'X' ;
                }
            }
        
    }
};