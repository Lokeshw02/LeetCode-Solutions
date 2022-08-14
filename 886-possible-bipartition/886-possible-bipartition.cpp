class Solution {
public:
    // -1 -> not visited 
    // Visited 0 - G1 
    //Visiteed 1 - G2 
    bool dfs(vector<vector<int>>&graph , int start, int color, vector<int>& visited){
        visited[start] = 1- color ;
        bool t = true ;
        
        for(auto nbr : graph[start]){
            if(visited[nbr] ==  -1)
                t = t && dfs(graph, nbr,1- color, visited) ;
            else if(visited[nbr] == 1- color)
                return false ;
        }
        
        return t ;
        
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> visited(n +1 , -1) ;
        vector<vector<int>> graph(n+1) ;
        
        for(int i = 0; i < dislikes.size(); i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]) ;
            graph[dislikes[i][1]].push_back(dislikes[i][0]) ;
        }
        
        bool res = true ;
        
        for(int i = 1; i <= n ;i++){
            if(visited[i] == -1)
                res = res && dfs(graph,i,0,visited) ;
        }
        
        return res ;
    }
};