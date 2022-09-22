class Solution {
public:
    
    void helper (vector<int>&nums, vector<int>&temp,vector<vector<int>> &res,int target,int i ){
        
        
        if(target == 0 ) 
        {
            res.push_back(temp) ;
            return ;
        }
        
        if(i >= nums.size() ) return ;
        
        if(target < 0 )return ;
        
        
        //Include 
        temp.push_back(nums[i]) ;
        helper(nums,temp,res, target - nums[i], i+1) ;
        
        
        temp.pop_back() ; 
        
        int prev = nums[i],j;
        
        for(j=i;j<nums.size() && nums[j]==prev;j++);
        
 
        helper(nums,temp,res,target,j) ;

    }
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<int> temp ;
        vector<vector<int>> res ; 
        sort(candidates.begin(), candidates.end()) ;
        
        helper(candidates, temp, res, target,0) ;
        
        return res ;
    }
};