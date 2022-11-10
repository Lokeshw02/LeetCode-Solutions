string order1, t ;

static bool fun(char &a, char &b){
    return order1.find(a) <  order1.find(b) ;
}


class Solution {
public:
    string customSortString(string order, string s) {
        
        order1 = order ;
        t = s ;
        
        sort(t.begin(), t.end(), fun) ;
        
        return t ;
        
    }
};