class Solution {
public:
    bool isPerfectSquare(int num) {
        
        long long  hi = num, lo = 0 , mid ;
        
        while(lo <= hi){
            
            mid = lo + (hi-lo)/2 ;
            
            if(mid*mid == num)
                return true ;
            
           else  if(mid*mid > num) 
                hi = mid -1 ;
            
            else
            {
                if( (mid+1)*(mid+1) > num    )
                    return false ;
                else 
                    lo = mid +1 ;
            }
            
        }
        
        return false ;
        
    }
};