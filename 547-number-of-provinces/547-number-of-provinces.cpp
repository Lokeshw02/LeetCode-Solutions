class Solution {
public:
    
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int n){
        
        visited[n] = true ;
        
        //Go throught the neighbours 
        
        for(int i = 0; i< isConnected.size() ;i++){
            if(!visited[i] && isConnected[n][i])
                dfs(isConnected,visited,i) ;
        }
    }
    
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size() ;
        vector<bool>visited(n, false) ;
        
        int count = 0 ;
        
        for(int i = 0 ; i< n ; i++ ){
            
            if(!visited[i]){
                count++ ;
                dfs(isConnected, visited, i) ;
            }
        }
        
        return count ;
        
    }
};