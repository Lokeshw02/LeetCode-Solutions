class Solution {
public:
    
    void helper(vector<int>& nums, vector<vector<int>>&res,vector<int> &temp,vector<int> &visited ){
        
        if(temp.size() == nums.size()) 
        {
            res.push_back(temp) ;
            return ;
        }
        
        for(int i = 0;i< nums.size() ; i++){
            
            if(visited[i] == 0) {
                visited[i] = 1 ;
                 temp.push_back(nums[i]) ;
                 helper(nums,res,temp,visited) ;
                visited[i] = 0 ;
                temp.pop_back() ;
                
            }
               
        }
        
        
    }
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res ;
        vector<int> temp ;
        vector<int> visited(nums.size(),0) ; 
        
        helper(nums,res,temp,visited) ;
        
        return res ;
        
        
    }
};