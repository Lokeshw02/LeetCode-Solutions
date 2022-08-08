class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //COnstruct the dictionary 
        unordered_set<string> dict (wordList.begin(),wordList.end()) ;
        
        unordered_set<string> visited ;
        queue<pair<string,int>> q ;
        
        q.push({beginWord,0}) ; 
        visited.insert(beginWord) ;
        
        //Start BFS 
        
        while(!q.empty()){

        string curr_word = q.front().first ;
        int dist = q.front().second ;
        q.pop() ;
            
            if(curr_word == endWord) return dist + 1; 
            
            //Go through the neighbours 
            
            string temp_word  = curr_word ;
            
            for(int i = 0 ; i< curr_word.size();i++){
                for(int j = 0; j<26; j++){
                    temp_word[i] = (char)(j + 'a') ;
                    
                    //If it exists in the dictionary and not visited yet 
                    //Add it to the enexlplored kist 
                    if(visited.find(temp_word) == visited.end() && dict.find(temp_word) != dict.end()){
                        visited.insert(temp_word) ;
                        q.push({temp_word,dist+1}) ;
                    }
                    
                    temp_word[i] = curr_word[i] ;
                }
            }
        
            
            }
        
        return 0 ;
        
    }
};