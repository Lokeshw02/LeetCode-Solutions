class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        
        unordered_map<int,int>m ;
        int pairs = 0 ;
        int rem = 0 ;
        
        for(int i : nums){
            m[i]++ ;
        }

        
        for(auto it = m.begin(); it != m.end(); it++){
            pairs += (it->second/2) ;
            it->second = it->second % 2 ;
            rem += it->second ;
        }
        
        return{pairs,rem} ;
        
    }
};