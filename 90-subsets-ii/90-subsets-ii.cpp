class Solution {
public:
    
     void helper(vector<int>&nums,int startIdx,vector<int>&currSet,vector<vector<int>>&res, bool prev ){
        
        int n = nums.size() ;
        
        if(startIdx == n ){
            res.push_back(currSet) ;
            return ;
        }
        
         //Include     
        currSet.push_back(nums[startIdx]) ;
        
        
        helper(nums,startIdx+1, currSet ,res,false)  ;
        
        currSet.pop_back() ;
       
         
        if( startIdx>0 && nums[startIdx] == nums[startIdx -1] && (!prev))
             return ;
        
       // Exclude 
        
         helper(nums, startIdx +1 ,currSet ,res, true) ;
         
        
              
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()) ;
        vector<vector<int>> res ;
        vector<int> currSet ;
        
        helper(nums,0,currSet,res,false) ;
        
        return res  ;
    }
};