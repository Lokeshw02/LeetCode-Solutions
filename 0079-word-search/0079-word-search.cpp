class Solution {
public:
    
    vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}} ;
    
    bool helper(vector<vector<char>>& board, string &word, int curr, int i, int j){
        
        if(curr == word.size()) 
            return true ;
        
        if(i < 0 || i >= board.size() || j < 0 || j >=board[0].size() || board[i][j] != word[curr])
            return false ;
        
        char temp = board[i][j] ;
        
        board[i][j] = '*' ; 
        
        bool t  = false ; ;
        
        for(auto &dir : dirs){
            
            int x = i + dir[0] ;
            int y = j + dir[1] ;
            
            t = t || helper(board,word,curr+1,x,y) ;
            
            
            
        }
        
        board[i][j] = temp ;
        
        return t ;
    } 
    
    
    bool exist(vector<vector<char>>& board, string word) {
      
        string curr ;
        
        for(int i = 0; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                
                if(board[i][j] == word[0] && helper(board,word,0,i,j)) 
                    return true ;
            }
        }
        
        return false ;
        
        
    }
};