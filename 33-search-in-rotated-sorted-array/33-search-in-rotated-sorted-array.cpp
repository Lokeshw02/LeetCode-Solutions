class Solution {
public:
    
    int searchPivot(vector<int>&nums){
        
        int lo = 0;
        int hi = nums.size() -1 ;
        int mid ;
        
        
        while(lo<hi){
            
            //FIRST 
            
            mid = lo + (hi-lo)/2 ;
            
            
            if(nums[nums.size()-1]-nums[mid] >= 0 ) //FFF*TTT   // First T 
                hi = mid ;
            else 
                lo = mid +1 ;   
            
            
        }
        
       if(lo == 0)
           return -1 ;
        
        return lo;
           
        
    }
    
    int searchNum(vector<int>&nums, int target, int lo, int hi){
        
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
            return lo ;
        
        return -1 ;
        
    }
    
    
    
    
    
        
    
    int search(vector<int>& nums, int target) {
        
        int pivot = searchPivot(nums);
        int res  ;
        
        cout<<pivot<<endl;
        
        if(pivot == -1) 
            return searchNum(nums,target,0,nums.size()-1);
        
        if(nums[pivot] == target)
            return pivot ;
        
        
        
        
        if(nums[nums.size()-1] >= target &&  target >= nums[pivot])
            //BInary search from pivot to end Index 
             res = searchNum(nums,target,pivot,nums.size()-1) ;
        else 
            //BInary search from  0 to pivot -1 
            
             res = searchNum(nums,target,0,pivot-1) ;
            
            
            return res ;
    }
};