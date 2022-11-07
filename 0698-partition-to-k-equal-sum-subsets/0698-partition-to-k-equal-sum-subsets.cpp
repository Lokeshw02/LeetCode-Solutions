class Solution {
public:
    
    
    
    bool helper(vector<int>& nums, vector<bool>& visited,int i, int currsum, int target, int k){
        
        if(k ==1 ) 
            return true ;
        
        if(i >= nums.size()) 
            return false ;
        if(currsum == target)
            return helper(nums,visited,0,0,target,k-1) ;
        
        
        for(int j = i ; j < nums.size() ; j++){
            
            if(visited[j] || currsum + nums[j] > target) continue ;
            
            visited[j] = true ;
            
            if(helper(nums,visited,j +1 , currsum + nums[j], target,k)) 
                return true ;
            
            visited[j] = false ;
        }
        
       return false ;
    }
    
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
     
        int n = nums.size() ; 
        vector<bool>visited(n,false) ;
        
        int sum = 0 ;
        
        for(int x : nums) 
            sum += x ;
        
        if(n < k || sum%k != 0) 
            return false ;
        
            return helper(nums,visited,0,0,sum/k,k) ;
    
    }
};