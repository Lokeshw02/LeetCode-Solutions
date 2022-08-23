class Solution {
public:
    vector<vector<int>>dirs = {{0,1},{1,0},{-1,0},{0,-1}} ;
    
    void dfs(int i, int j,vector<vector<char>>& board, vector<vector<bool>>&visited,int n, int m){
        
        if(board[i][j] == 'X' || visited[i][j] ) return ; 
        
        visited[i][j] = true  ;
        
        //Go thorough the neigbours 
        
        for(auto &dir : dirs){
            int x = i + dir[0] ;
            int y = j + dir[1] ;
            
            if(x>=0 && y >=0 && x < n && y <m && board[x][y] == 'O' && !visited[x][y])
                dfs(x,y,board,visited,n,m) ;
        }
    }

    
    
    void solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size() ;
        vector<vector<bool>>visited(n,vector<bool>(m,false)) ;
        
        //run  dfs on from the boundaries 
        
        //left - right 
        for(int i= 0 ; i< n ; i++){
            dfs(i,0,board,visited,n,m) ;
            dfs(i,m-1,board,visited,n,m) ;
            
        }
        //Top-Down 
         for(int j= 0 ; j< m ; j++){
            dfs(0,j,board,visited,n,m) ;
            dfs(n-1,j,board,visited,n,m) ;
            
        }
        
         for(int i= 0 ; i< n ; i++){
         for(int j= 0 ; j< m ; j++){
          
             if(board[i][j] == 'O' && !visited[i][j]) 
                 board[i][j] = 'X' ;
          
        }
        }
        
        
        
    }
};