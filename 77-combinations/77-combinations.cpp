class Solution {
public:
    
    void helper(int startIdx ,int n, int k, vector<int>&currSet, vector<vector<int>>&res){
        
        //Base Case 
        
        //Positive
        if(k==0) {
            res.push_back(currSet) ;
            return ;
        }
        
        //Negative 
        if(startIdx>n) return ;
        
      
        //Pruning Step 
        if(n-startIdx+1 < k) return ;
        
        //Exlcude
        
        helper(startIdx +1,n,k,currSet,res) ;
        
        //Include 
        
        currSet.push_back(startIdx) ;
        
        helper(startIdx+1,n ,k-1,currSet,res) ;
        
        currSet.pop_back() ;
        
        
        
    }
    
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res ;
        vector<int>currSet ;
        
        helper(1,n,k,currSet,res) ;
        
        return res ;
    }
};