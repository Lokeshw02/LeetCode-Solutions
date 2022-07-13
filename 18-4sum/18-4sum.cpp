class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        if(nums.size()<4) return {} ;
        
        
        vector<vector<int>> res ;
        
        sort(nums.begin(),nums.end()) ;
        
        for(int i = 0 ; i < nums.size()-3 ; i++){
            
            if(i>0 && nums[i] == nums[i-1]) continue ;
     
            for( int j = i+1 ; j  <  nums.size() -2 ; j++){
                
                 if(j>i+1 && nums[j] == nums[j-1]) continue ;
                
                int lo = j+1 ;
                int hi = nums.size() -1 ;
                
                
                while(lo<hi){
                    
                    long long total =  (long)nums[i]+(long)nums[j]+(long)nums[lo]+(long)nums[hi] ;
                    
                     if(total == target){
                    
                     res.push_back({nums[i],nums[j],nums[lo],nums[hi]}) ;
                         
                         
                      while(lo < nums.size() -1 && nums[lo] == nums[lo+1]) lo++ ;
                      while(hi > 0 && nums[hi] == nums[hi-1]) hi-- ;
                         
                      lo ++ ;
                      hi -- ;
                    
                      }
                    
                    else if (total > target)
                        hi-- ;
                    
                    else 
                        lo++ ;
                    
                    
                   
                }
                
               
                
                
                
                
            }
            
            
        }
        
        return res ;
    }
};