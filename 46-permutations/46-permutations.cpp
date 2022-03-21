class Solution {
public:
    
    void helper(vector<int>&arr, vector<int>&visited, vector<int>&currSet,vector<vector<int>>&res){
        
        if(currSet.size() == arr.size()){
            res.push_back(currSet) ;
            return ;
        }
        
        for( int i = 0; i< arr.size() ;i++){
            
            if(visited[i] == 0){
                visited[i] = 1 ;
                currSet.push_back(arr[i]) ;
                helper(arr,visited,currSet,res) ;
            
                visited[i] = 0 ;
                currSet.pop_back() ;
            }
            
            
            
        }
        
    }
     
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res ;
        vector<int>currSet ;
        vector<int>visited(nums.size(),0) ;
        helper(nums,visited,currSet,res) ;
        
        return res ;
    }
};