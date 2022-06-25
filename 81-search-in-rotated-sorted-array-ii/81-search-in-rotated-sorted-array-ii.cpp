class Solution {
public:
    
     int searchPivot(vector<int>&nums){
        
       for (int i =0 ;i < nums.size()-1;i++){
           
           if(nums[i+1]<nums[i])
               return i+1 ;
           
          
    }
          return -1 ; 
     }
    
    bool searchNum(vector<int>&nums, int target, int lo, int hi){
        
        int mid ;
        
        
        while(lo<hi){
            
            //FIRST 
            
            mid = lo + (hi-lo)/2 ;
            
            
            if(nums[mid] >= target ) //FFF*TTT   // First T 
                hi = mid ;
            else 
                lo = mid +1 ;   
            
            
        }
        
        if(nums[lo] == target)
            return true ;
        
        return false ;
        
    }
    
       
    
    
    bool search(vector<int>& nums, int target) {
        
        
        if(nums.size() == 1 && nums[0] == target) return true ; 
         if(nums.size() == 1 && nums[0] != target) return false ; 
        
        int pivot = searchPivot(nums);
        bool res  ;
        
        cout<<pivot<<endl;
        
        if(pivot == -1) 
            return searchNum(nums,target,0,nums.size()-1);
        
        if(nums[pivot] == target)
            return true ;
        
        
        
        
        if(nums[nums.size()-1] >= target &&  target >= nums[pivot])
            //BInary search from pivot to end Index 
             res = searchNum(nums,target,pivot,nums.size()-1) ;
        else 
            //BInary search from  0 to pivot -1 
            
             res = searchNum(nums,target,0,pivot-1) ;
            
            
            return res ;
        
    }
     
};