class Solution {
public:
    
    void helper(vector<int>& nums, vector<vector<int>>& res,  vector<int> &temp, int i, bool prev){
        
        if(i >= nums.size()){
            res.push_back(temp) ;
            return ;
        }
        
        //Include 
        temp.push_back(nums[i]) ;
        
        helper(nums,res,temp,i+1,false) ;
        
        temp.pop_back() ;
        
        if(i > 0 && nums[i] == nums[i-1] && !prev)
            return ;
        //Exclude
        
        helper(nums,res,temp, i+1, true) ;
        
        
    }
    
    
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>>res;
        vector<int> temp ;
        sort(nums.begin(), nums.end()) ;
        
        helper(nums,res,temp,0,false) ;
        
        return res ;
        
        
    }
};