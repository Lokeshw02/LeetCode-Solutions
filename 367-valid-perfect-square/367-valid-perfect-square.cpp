class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num ==1) return true ;
        
       long long  int lo = 0, hi = num/2, mid ;
        
        while(lo<hi){
            
            mid = lo + (hi-lo)/2 ;
                
            if(mid*mid == num) return true ;
            
            if(mid*mid>=num)
                hi = mid;
            else
                lo = mid+1 ;
            
        }
        
       if(lo*lo == num) return true ;
       return false ;
    }
};