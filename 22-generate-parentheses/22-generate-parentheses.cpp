class Solution {
public:
    
    void helper(vector<string> &res, string &temp, int &open, int &close, int n){
        
        
        if(open == n && close == n){
            res.push_back(temp) ;
            return ;
        }
        
        
        
        if(open < n){
            open++ ;
            temp += '(' ;
            helper(res,temp,open,close,n) ;
            open-- ;
            temp.pop_back() ;
        } 
        
        if(close < open){
            close++ ;
            temp += ')' ;
            helper(res,temp,open,close,n) ;
            close-- ;
            temp.pop_back() ;
        } 
        
        
    }
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> res ;
        string temp = "" ;
        int open = 0, close = 0 ;
        
        helper(res,temp,open,close,n) ;
        
        return res ;
    }
};