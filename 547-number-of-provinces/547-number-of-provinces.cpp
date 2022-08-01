class Solution {
public:
    void dfs(int n, vector<bool>&visited, vector<vector<int>>graph){
        visited[n] =  true ;
        
        for(int j = 0 ; j < graph[n].size(); j++){
            if(graph[n][j] && !visited[j])
                dfs(j,visited,graph) ;
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<bool>visited(isConnected[0].size(),false) ;
        int res = 0 ;
        
        for(int i = 0 ; i < isConnected.size() ; i++){
            if(!visited[i]){
                dfs(i,visited,isConnected) ;
                res ++ ;
            }
        }
        
        return res ;
    }
};