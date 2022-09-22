class Solution {
public:
    
    void helper(vector<int>& nums, int target,  vector<int>& temp, vector<vector<int>> &res, int i ){
        
          if(i >= nums.size()) 
            return ;
        
         if(target < 0 ) return ;
        
        
        if(target == 0 ){
            res.push_back(temp) ;
            return ;
        }
        
       
        
      
        
        //Include 
        temp.push_back(nums[i]) ;
        
        helper(nums,target-nums[i], temp,res,i) ; 
        
        temp.pop_back() ;
        
        //Exclude 
        
        helper(nums,target, temp, res, i+1) ;
      
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp ;
        vector<vector<int>> res ;
        
        helper(candidates,target,temp,res,0) ;
        
        return res ;
        
        
    }
};