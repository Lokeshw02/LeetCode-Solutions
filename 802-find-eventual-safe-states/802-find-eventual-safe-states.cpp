class Solution {
public:
    
    int hasCycle(vector<vector<int>>& graph, vector<int>&visited, vector<int>&path, int n){
        
        path[n] = true ;
        
        int safe = 1, t  ;
        
        //Go thrigh the neighbours 
    // 0 is unviisted, 1 is safe , 2 is unsafe 
        
        for(auto &nbr : graph[n]){
            
            if(path[nbr]) 
                safe = 2 ;
            
            else if(!visited[nbr]){
                 t = hasCycle(graph,visited,path,nbr) ;
                if( t == 2 )
                safe = t ;
                
            }
            else if(visited[nbr] == 2) 
                safe = visited[nbr] ;
             
        }
        
        path[n] = false ;
        visited[n] = safe ;
        
        return safe ;
        
    }
    
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size() ;
        
        vector<int>visited(n,0) ;
        vector<int>path(n,0) ;
        vector<int>res ;
        
        for(int i  = 0; i < n ; i++){
            if(!visited[i]) 
                int t = hasCycle(graph,visited,path,i) ;
        }
        
        for(int i = 0; i < n ; i++){
            if(visited[i] == 1) 
                res.push_back(i) ;
        }
        return res ;
    }
};