class Solution {
public:
    
    void solve(int idx,string &digits, vector<string> &res, string &temp, vector<string> &m ){
        
        if(idx>= digits.size()){
            res.push_back(temp) ;
            return ;
        }
        
        int x = digits[idx] - '0' ;
        string v = m[x] ;
        
        for(int i = 0; i< v.size(); i++){
            temp.push_back(v[i]) ;
            solve(idx+1,digits,res,temp,m) ;
            temp.pop_back() ;
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.size() == 0) return {} ;
        
        vector<string> res  ;
        string temp = "" ;
        
        vector<string> m = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"} ;
        
        solve(0,digits,res,temp,m) ;
        
        return res ;
    }
};