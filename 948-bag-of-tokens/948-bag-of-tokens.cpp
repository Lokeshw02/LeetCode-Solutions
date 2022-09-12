class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        if(tokens.size() == 1) {
            return tokens[0] < power ;
        }
            
        
        
        
        sort(tokens.begin(),tokens.end()) ;
        int i = 0, j = tokens.size() -1 ;
        int score = 0 ;
        
        while(i<=j){
            
            while(tokens[i] <= power && i <= j){
                power = power - tokens[i] ;
                score++ ;
                i++ ;
            }
            
            if(i>=j || score <= 0) break ;
            score-- ;
            power += tokens[j] ; 
            j-- ;
        }
    
      return score ;
    
    }
};