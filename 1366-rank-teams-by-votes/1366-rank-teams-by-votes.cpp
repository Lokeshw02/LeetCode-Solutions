class Solution {
public:
    string rankTeams(vector<string>& votes) {
        //n is no of teams
        //m is no of votes
        int n = votes[0].size();
        int m = votes.size();
        
       vector<vector<int>>rank(26,vector<int>(n,0)) ;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rank[votes[i][j]-'A'][j]++ ;
            }
    }
        
    string res = votes[0];
        sort(res.begin(),res.end(),[=](char&a,char&b){
            for(int i=0;i<n;i++){
                //if theere is a class level voting 
                if(rank[a-'A'][i] == rank[b-'A'][i])
                    continue;
                //
                else return rank[a-'A'][i]>rank[b-'A'][i]; 
                    
            }
            return a<b ;
            
        });
        return res;
    }
    
};