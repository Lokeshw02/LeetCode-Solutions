class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int i = 0, j = 0 , count = 0;
        
        sort(ransomNote.begin(),ransomNote.end()) ;
          sort(magazine.begin(),magazine.end()) ; 
        
        
                

                

        
        
        while(i < magazine.size() && j < ransomNote.size()){
            if(magazine[i] == ransomNote[j]) {
                i++ ;
                j++ ;
                count++ ;
            }
            else{
                i++ ;
            }
        }
        
        if(count == ransomNote.size()) return true ;
        return false ;
    }
};