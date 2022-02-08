class Solution {
public:
    
    void helper(vector<int>&arr, int sum, int startIdx, vector<int> &currSet,vector<vector<int>>&res){
        
        if(sum ==0 )
        { 
            res.push_back(currSet) ;
            return  ;}
        
        if(sum<0) return ;
        
        int n = arr.size() ;
        
        
        
        if(startIdx == n ) return ;
        
       if(sum < arr[startIdx]) return ;
        
        //Include the intial elment or starts with it
        
        currSet.push_back(arr[startIdx]);
        
        helper(arr,sum-arr[startIdx],startIdx+1,currSet,res) ;
        
        currSet.pop_back() ;
        
        // This while loop did not work here 
//         int prev = arr[startIdx], i ;
//         i = startIdx  ;
        
        
//     while(arr[i] == prev && i<arr.size()) {
//         i++ ;
//        }
        
        
         int prev = arr[startIdx] ,i ;
        
        for(i = startIdx;i<arr.size() && arr[i] == prev ;i++) ;
        
        helper(arr,sum,i,currSet,res) ;
              
    }
    
    
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end()) ;
        vector<int>currSet;
        vector<vector<int>>res ;
        
        helper(candidates,target,0,currSet,res);
        
        return res ;
    }
};


