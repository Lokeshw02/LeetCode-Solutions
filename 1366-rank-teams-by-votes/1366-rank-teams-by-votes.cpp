class Solution {
public:
    string rankTeams(vector<string>& votes) {
       
        int n = votes.size() ; //No of Votes 
        int m = votes[0].size() ; //No of teams 
        
        vector<vector<int>>rank(26,vector<int>(m,0)) ;
        
       for(int i = 0; i<n ;i++){
            for(int j =0; j<m ;j++){
                rank[votes[i][j] - 'A'][j] ++ ;
                
            }
        }
        
        string res = votes[0] ;
        
        sort(res.begin(),res.end(),[=](char &a, char &b){
            
            for(int i = 0 ; i < m ; i++){
                
                if(rank[a - 'A'][i] == rank[b - 'A'][i])
                    continue ;
                else 
                    return rank[a - 'A'][i] > rank[b - 'A'][i] ;
                
                
            }
            return a<b ;
            
            
            
        }) ;
        
       return res ;
    }
    
};