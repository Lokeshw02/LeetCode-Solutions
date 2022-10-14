class Solution {
public:
    
//     bool helper(vector<int>& nums, int mid){
        
//         int min_ = INT_MAX ;
        
//         for(int i = 0; i < nums.size() ; i++){
//             mid += nums[i] ;
//             min_ = min(min_,mid) ;
//         }
        
//         return min_ >= 1 ;
//     }
    
    int minStartValue(vector<int>& nums) {
        
//         int lo = 1 , hi = 10000, mid ;
        
//         while(lo <= hi){
            
//             mid = lo + (hi-lo)/2 ;
            
//             if(helper(nums,mid)) 
//             {
//                 if( mid-1 != 0 && !helper(nums,mid-1)) 
//                     return mid ;
//                 else 
//                     hi = mid -1 ;
                    
//             }
            
//             else
//             {
//                 lo = mid +1 ;
//             }
//         }
        
//         return mid ;
        int min_ = INT_MAX ;
        int prefsum = 0 ;
        
        for(int i = 0; i < nums.size() ; i++){
            
            prefsum += nums[i] ;
            
            min_ = min(min_,prefsum) ;
         
        }
        
        return min_>0 ? 1 : abs(min_) +1 ;
    }
};