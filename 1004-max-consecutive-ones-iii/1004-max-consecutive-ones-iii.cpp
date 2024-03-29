class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
       int i = 0, j = 0, max_ = 0 ;
       int n = nums.size() ;
        int count = 0 ;
        
      while(j < n){
          
          if(nums[j] == 0)
              count++ ;
          if(count < k){
              max_ = max(max_,j-i+1) ;
              j++ ;
          }
          else if (count == k){
              max_ = max(max_, j-i+1) ;
              j++ ;
          }
          else if(count > k){
              while(count > k){
                  if(nums[i] == 0) 
                      count-- ;
                  i++ ;
              }
              j++ ;
          }
      }
        
        return max_ ;
    }
};