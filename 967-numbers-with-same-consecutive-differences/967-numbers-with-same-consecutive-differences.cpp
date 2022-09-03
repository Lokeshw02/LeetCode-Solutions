class Solution {
public:
    
    int digits(int n){
        int count = 0 ;
        while(n){
            n = n/10 ;
            count++ ; 
        }
        return count ;
    }
    
    void helper(int n, int k , int currdigit, vector<int>& res ){
        
        if(digits(currdigit) == n ){
            res.push_back(currdigit) ;
            return ;
        }
        
        for(int i = 0; i < 10 ; i++){
            int lastdigit = currdigit %10 ;
            if(abs(lastdigit - i) == k)
                helper(n,k,currdigit*10 + i ,res) ;
        }
    }
    
    
    
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res ;
        
        for(int i = 1 ; i < 10 ; i++){
            
            helper(n,k,i,res) ;
            
        }
        
        return res ;
    }
};