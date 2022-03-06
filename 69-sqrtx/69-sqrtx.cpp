class Solution {
public:
    int mySqrt(int x) {
        
        
        if(x==1 || x==0) return x ;
        
       long long  int lo = 0, hi = x/2  ;
        
       long long  int  mid ;
        
        while(lo<hi){
            
            //FFF*TTTT
            
             mid = lo +(hi-lo+1)/2 ;
            
            if(mid*mid == x) return mid ;
            
            if(mid*mid >= x)
             hi  = mid -1 ;
            
            else 
                lo = mid;
        }
        
      return lo ;
        
       
    }
};



// int Solution::sqrt(int A) {
//     long long lo = 1, hi = A/2,mid ;
    
//     if(A==1) return 1;
//     if(A==0) return 0;
//     if(A==2) return 1;
//     if(A==3) return 1;
//     if(A == 4) return 2;
//     int ans = 0;
//     while(lo<=hi){
//         mid = (hi + lo) / 2;
        
//         if(mid*mid == A)
//             return mid;
            
//         if(mid*mid <= A) {
//             lo = mid + 1;
//             ans = mid;
//         } else {
//             hi = mid - 1;
//         }
 
//     } 
//     return ans;

// }
