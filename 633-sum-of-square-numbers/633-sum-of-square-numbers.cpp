class Solution {
public:
    bool judgeSquareSum(int c) {
        
    long long  int left = 0 ;
     long long int right = sqrt(c) ;
        
    while(left <= right){
        
        long long cal = left*left + right*right ;
        
        if(cal < c) 
            left ++ ;
        
        else if(cal > c) 
            right -- ;
        
        else 
            return true ;
        
   
    }
      
        
        return false ;
        
    }
};