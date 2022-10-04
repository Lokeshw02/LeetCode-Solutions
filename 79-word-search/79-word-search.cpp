class Solution {
public:
    
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}} ;
    
    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int count){
        if(count == word.size()) 
            return true ;
        
        bool t = false  ;
        
        if(i <0 || i >= board.size() || j <0 || j >= board[0].size() || word[count] != board[i][j])
            return false ;
        
        char temp = board[i][j] ;
        
         temp = board[i][j] ;
        
          board[i][j] = '*' ;
         
        for(auto & dir : dirs ){
            int x = i + dir[0] ;
            int y = j + dir[1] ;
            
            t = t || dfs(board,word,x,y,count+1) ;
            
        }
        board[i][j] = temp ;
        
        return t ;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                
                if( board[i][j] == word[0] && dfs(board,word,i,j,0) )  
                    return true ;
                    
                    
            }
        }
        return false ;
        
    }
};