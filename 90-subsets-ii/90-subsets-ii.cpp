class Solution {
public:
    
    void helper(vector<int>&nums, vector<int>&curr, vector<vector<int>>&res, int idx, bool ignore){
        
        if(idx >= nums.size()){
            res.push_back(curr) ;
            return ;
        }
        
        //include Exclude 
        curr.push_back(nums[idx] ) ; 
        helper(nums,curr,res,idx+1,false) ;
        
         curr.pop_back() ;
        //Exclude 
        
        if(idx>0 && nums[idx] == nums[idx-1] && !ignore) 
            return ;
       
        
        helper(nums,curr,res,idx+1,true) ;
        
       
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ;
        vector<int>curr; vector<vector<int>>res ;
        
        helper(nums,curr,res,0,false) ;
        
        return res ;
        
    }
};