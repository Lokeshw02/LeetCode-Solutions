// string temp ;

// bool compare(char &a , char &b){
//     return temp.find(a) < temp.find(b) ;
// }



class Solution {
public:
    string customSortString(string order, string s) {
        
        sort(s.begin(),s.end(),[order](char &a, char &b){
            return order.find(a)<order.find(b) ;
        }) ;
        return s ;
    }
};