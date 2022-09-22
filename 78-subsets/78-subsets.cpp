class Solution {
public:
    
    void helper(vector<int>& nums,vector<int>&temp,vector<vector<int>> &res, int i){
        
        if(i >= nums.size()){
            res.push_back(temp) ;
            return ;
        }
        
        //Include 
        temp.push_back(nums[i]) ;
        helper(nums,temp,res,i+1) ;
        
        temp.pop_back() ;
        
        //Exclude 
        
        helper(nums,temp,res,i+1) ;
    }
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp ;
        vector<vector<int>> res ;
        
        helper(nums,temp,res,0) ;
        
        return res ;
        
    }
};