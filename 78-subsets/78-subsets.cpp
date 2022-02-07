class Solution {
public:
    
    void helper(vector<int>&nums,int startIdx,vector<int>&currSet,vector<vector<int>>&res){
        
        int n = nums.size() ;
        
        if(startIdx == n ){
            res.push_back(currSet) ;
            return ;
        }
        
        //Include     
        currSet.push_back(nums[startIdx]) ;
        
        
        helper(nums,startIdx+1, currSet ,res)  ;
        
       
       
         currSet.pop_back() ;
        
       // Exclude 
        
         helper(nums, startIdx +1 ,currSet ,res ) ;
        
        
    }
    
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>currSet ;
        vector<vector<int>> res ;
        
        helper(nums,0,currSet,res) ;
        
        return res ;
    }
};