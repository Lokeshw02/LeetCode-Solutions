class Solution {
public:
    
    void helper(int n, int k, int i,vector<int> &temp, vector<vector<int>> &res ){
        
        if(k  == 0 ){
            res.push_back(temp) ;
            return ;
        }
        
        if(i > n) 
            return  ;
        
        if(n-i +1 < k ) 
            return ;
        
        if(k<0) return ;
        
        //Include
        temp.push_back(i) ;
        helper(n,k-1,i+1,temp,res) ;
        temp.pop_back() ;
        
        //Exclude 
        
        helper(n,k, i+1,temp, res ) ;
        
    }
     
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res ;
        vector<int> temp ;
        
        helper(n,k,1,temp,res) ;
        
        return res ;
    }
};