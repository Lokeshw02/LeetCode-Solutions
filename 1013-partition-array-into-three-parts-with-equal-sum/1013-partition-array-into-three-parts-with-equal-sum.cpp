class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(),arr.end(),0) ;
        
        if(sum % 3 != 0)
            return false ;
        int req = sum/3 ;
        int count = 0 ;
        int temp = 0 ;
        
        for(int i = 0; i < arr.size() ; i++){
            
            temp += arr[i] ;
            if(temp == req){
                count ++ ;
                temp = 0 ;
            }
        }
        
        return count >= 3 ;
 
            
    }
};