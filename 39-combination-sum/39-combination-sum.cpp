class Solution {
public:
    void helper(vector<int>& candidates, int sum, int startIdx,vector<int>&currSet, vector<vector<int>>& res){
        
        if(sum ==0){
            res.push_back(currSet) ;
            return ;
        }
        
        if(startIdx>=candidates.size()) return ;
        
        if(candidates[startIdx]>sum) return ;
        
        //Include 
        currSet.push_back(candidates[startIdx]) ;
        helper(candidates,sum-candidates[startIdx],startIdx,currSet,res) ;
        currSet.pop_back() ;
        
        
        
        //Exclude 
        
         helper(candidates,sum,startIdx+1,currSet,res) ;
    }
    
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end()) ;
        vector<int> currSet ;
        vector<vector<int>> res ;
         helper(candidates,target,0,currSet,res) ;
        
        return res ;
        
        
    }
};