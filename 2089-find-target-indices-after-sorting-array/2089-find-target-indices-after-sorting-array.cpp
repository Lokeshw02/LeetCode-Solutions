class Solution {
public:
    
    vector<int>ans ;
    
    void BS(vector<int>&nums, int lo, int hi,int target){
        
      if(lo>hi)
          return ;
        
        
        int mid = lo +(hi-lo)/2 ;
        
    if(nums[mid] == target){
        
        BS(nums,mid+1,hi,target) ;
        ans.push_back(mid) ;
        BS(nums,lo,mid-1,target) ;
        
     
        
    }
        
        else if(nums[mid]>target){
            
            BS(nums,lo,mid-1,target);
            
          
                
        }
        
           else
                 BS(nums,mid+1,hi,target);
               
     
        
    }

    
    
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end()) ;
        
        BS(nums,0,nums.size()-1,target);
        
        sort(ans.begin(),ans.end()) ;
        
        return ans ;

    }
};