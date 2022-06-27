class Solution {
public:
    int findNthDigit(int n) {
        long long digits = 9 ;
        int length = 1 ;
        int first  = 1 ;
        
        while(n>length*digits){
         
            n -= length*digits ;
            length++ ;
            first *= 10 ;
            digits *= 10 ;
            
        
        
        }
        
        first += (n-1)/length ;
        
        string digitString = to_string(first) ;
        
        char res =  digitString[(n-1)%length] ;
        
        //ut<<res<<endl;
        
        int res1 = res - '0' ;
        
        return res1 ;
        
        
    }
};