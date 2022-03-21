class Solution {
public:
    
     void helper(vector<int>&arr, vector<int>&visited, vector<int>&currSet, vector<vector<int>>&res){
         if(currSet.size() == arr.size()){
             res.push_back(currSet) ;
             return ;
         }
         
         for(int i = 0 ;i<arr.size();i++){
             
             if(visited[i] == 0){
                 
                 visited[i] = 1 ;
                 currSet.push_back(arr[i]) ;
                 helper(arr,visited,currSet,res) ;
                 visited[i] = 0 ;
                 currSet.pop_back() ;
                 
//                    while(i<arr.size()-1 && arr[i] == arr[i+1]) i++ ;
                 
                    int j ;
                    
                 for(j =i ; j<arr.size()-1 && arr[j] == arr[j+1];j++) ;
                 i = j ;
                 
             }
             
          
              
             
             
         }
             
         
         
         
         
     }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int>currSet;
        vector<int> visited(nums.size(),0);
        helper(nums,visited,currSet,res);
        
        return res  ;
        
    }
};