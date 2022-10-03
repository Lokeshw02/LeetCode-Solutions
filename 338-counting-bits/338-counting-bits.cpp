class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res ;
        
//         for(int i = 0; i <= n ;i++){
//             int x =  __builtin_popcount(i) ;
//             res.push_back(x) ;
//         } 
        
        res.push_back(0) ;
        
        for(int i = 1; i <= n ;i++){
            res.push_back(res[i&(i-1)] +1 ) ;
        }
        return res ;
    }
};