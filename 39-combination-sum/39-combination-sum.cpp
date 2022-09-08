class Solution {
public:
    
    void helper(vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& res, int idx ){
        
        
        if(idx >= candidates.size() ) return ;
        
        
            
        if(target == 0 ){
         res.push_back(temp) ;
         return ;
        }
            
         
    
        
        if(target < 0) return ;
        
        //Include 
        temp.push_back(candidates[idx]) ;
        helper(candidates,target - candidates[idx], temp, res , idx) ;
        
        //Exclude 
        temp.pop_back() ;
        helper(candidates,target , temp, res , idx +1 ) ;
        
        
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res ;
        vector<int> temp ;
        
        helper(candidates,target,temp,res,0) ;
        
        return res ;
    }
};