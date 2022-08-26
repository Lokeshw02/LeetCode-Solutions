class Solution {
public:
    
    
    vector<string> arr ;
    bool reorderedPowerOf2(int n) {
        
        long long x = n ;
        
        for(int i = 0 ; i <= 30 ; i++){
            
            x = pow(2,i) ; 
            string s =  to_string(x); 
            sort(s.begin(),s.end()) ;
            
            arr.push_back(s) ;
            
        }
        
        string r = to_string(n) ;
        
        sort(r.begin(),r.end()) ;
        
        sort(arr.begin(),arr.end()) ;
        
        int t = lower_bound(arr.begin(),arr.end(),r) - arr.begin() ; 
        
        return arr[t] == r ;
        
    }
};