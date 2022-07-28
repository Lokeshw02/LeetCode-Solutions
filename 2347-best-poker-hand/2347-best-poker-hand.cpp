class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        
        int countA = 0 ;
        int countB = 0 ;
        int countC = 0 ;
        int countD = 0 ;
        
        for(int i = 0; i< suits.size();i++){
            
            if(suits[i] == 'a') countA++ ;
            if(suits[i] == 'b') countB++ ;
            if(suits[i] == 'c') countC++ ;
            if(suits[i] == 'd') countD++ ;
        }
        
       vector<int>freq(14,0) ;
        
        for(int i = 0 ; i<ranks.size() ; i++){
            freq[ranks[i]] ++ ;
        }
        
        if(countA == 5 || countB == 5 || countC == 5 || countD == 5 ){
            return "Flush" ;
        }
        
        for(int x : freq){
            if( x >= 3) 
                return "Three of a Kind" ;
        }
        
        for(int x : freq){
            if( x == 2) 
                return "Pair" ;
        }
        
        return "High Card" ;
        
        
        
    }
};