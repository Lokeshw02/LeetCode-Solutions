string temp ;

bool compare(char &a , char &b){
    return temp.find(a) < temp.find(b) ;
}



class Solution {
public:
    string customSortString(string order, string s) {
        temp = order ;
        sort(s.begin(),s.end(),compare) ;
        return s ;
    }
};