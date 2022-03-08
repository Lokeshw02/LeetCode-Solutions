class Solution {
public:
    
    int getuniquelength(vector<string>&arr, string str,int i){
        
        if(i == arr.size() ){
            vector<int> freq(26,0) ;
            for(int j = 0; j<str.length();j++){
                if(freq[str[j] - 'a']) 
                    return 0 ;
                freq[str[j] - 'a']++ ;
            }
            
            return str.length() ;
        }
            
        
    
    int inc_len = 0 ;
    
    if(str.length() + arr[i].length() <= 26)
        inc_len = getuniquelength(arr,str + arr[i],i+1) ;  
        
     
        int exc_len = getuniquelength(arr,str,i+1);
    
        return max(inc_len,exc_len);
    
}

    
    
    int maxLength(vector<string>& arr) {
      
       return  getuniquelength(arr,"",0) ;
        
        
    }
};