class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s) ;
        
        string t , res ;
        
        while(getline(ss,t,' ')){
            reverse(t.begin(), t.end()) ;
            res += t + " " ;
        }
        
        return res.substr(0,res.size()-1) ;
    }
};