class Solution {
public:
    
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}} ;
    
    bool helper(vector<vector<char>>& board, string &word, int i, int j, int count ){
        if(count == word.size()) {
            return true ;
        }
        
        if(i <0 || j <0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[count]) 
            return false ;
        
        char temp = board[i][j] ;
        
        board[i][j] = '*' ;
        
        bool found = false ;
        
        for(auto &dir : dirs ){
            int x = i + dir[0] ;
            int y = j + dir[1] ;
            
            found = found || helper(board,word,x,y,count+1) ;
        }
        
        board[i][j] = temp ;
        
        
        return found ;
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                
                if(board[i][j] == word[0] && helper(board,word,i,j,0)) 
                    return true ;
            }
        }
        
        return false ;
    }
};