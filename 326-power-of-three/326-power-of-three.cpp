class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n==0) return false ;
        
//         double x = log(n)/log(3) ;
        
//         if(ceil(x) == floor(x) ) return true ;
        
//         return false ;
        
        while(n%3 == 0) n = n/3 ;
        
        return n == 1 ;
            
            
            
            
            
            
        
    }
};