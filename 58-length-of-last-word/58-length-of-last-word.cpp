class Solution {
public:
    int lengthOfLastWord(string s) {
        
        
        
        int from, to , count = 0  ;
        
        for(int i = s.size()-1; i>= 0 ; i--){
            
            if(s[i] != ' ') {
                 from = i ;
                 break ;
            }
               
        }
        
        while( from >= 0 && s[from] != ' ' ){
            count++ ;
            
            from-- ;
        }
        
        return count ;
    }
};