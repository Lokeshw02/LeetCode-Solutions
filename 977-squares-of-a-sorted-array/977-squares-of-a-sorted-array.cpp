class Solution {
public:
    
    static bool comp(int &a, int &b){
        
        return (long long)a*a < (long long)b*b ;
    }
    
    
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int > res ;
        
        for(int i : nums){
            res.push_back(i*i) ;
        }
        
        sort(res.begin(),res.end(),comp) ;
        
        return res ;
    }
};