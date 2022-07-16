class Solution {
public:
    int countPrimes(int n) {
        
        
        // if(n<=2) return 0 ; 
        // if(n == 3) return 1 ;
        
        
        vector<bool>arr(n+1,true) ;
        
        for(int i = 2; i*i < n ; i++){
            
            if(arr[i]) {
                for(int j = i*i ; j< n ; j += i)
                    arr[j] = false ;
            }
        }
        
        int count = 0 ;
        
        for(int i = 2 ; i< n ;i++){
            if(arr[i])
                count++;
        }
        
        
        return count ;
        
        
    }
};