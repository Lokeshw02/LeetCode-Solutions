class Solution {
public:
    
//     int firstN( long long int k){
        
//         return k*(k+1)/2 ;
//     }
    
    
    int arrangeCoins(long int n) {
        
        
//         if(n == 0 || n==1) return n ;
     
         
//          long long int lo = 0, hi = n, mid  ;
        
//         while(lo<hi){
            
//             mid = lo + (hi-lo)/2 ; 
            
//             if(firstN(mid) == n) return mid ;
                
//             if(firstN(mid)>=n)
//                 hi = mid ;
//             else 
//                 lo = mid +1 ;
//         }
        
//        if(firstN(lo)==n)
//            return int(lo);
        
//         return int(lo-1);
    
      return sqrt(2 * (long long)n + 0.25) - 0.5;
    
    }
};