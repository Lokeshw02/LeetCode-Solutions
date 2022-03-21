class Solution {
public:
    
    
    void helper(int startIdx,int n, int k,vector<int>&currSet,vector<vector<int>>&res){
        
        if(k==0) {
            res.push_back(currSet) ;
            return ;
        }
        
        if(startIdx>n) 
            return ;
        
        if(n-startIdx+1 < k) return ;
        
        //Include 
        currSet.push_back(startIdx) ;
        
        helper(startIdx+1,n,k-1,currSet,res) ;
        
        currSet.pop_back() ;
        
        //Exclude 
        
        helper(startIdx+1,n,k,currSet,res) ;
        
        
        
        
    }
    
    
    
    
    
    
    vector<vector<int>> combine(int n, int k) {
    
         vector<int>currSet ;
         vector<vector<int>>res ;
         
        helper(1,n,k,currSet,res) ;
        
        return res ;
        
        
    }
};