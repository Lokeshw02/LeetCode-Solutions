class Solution {
public:
     vector<int>parent ;
    
    
    void merge(int u, int v){
        int g1 = find(u) ;
        int g2 = find(v) ;
        
        parent[g2] = g1 ;
    }
    
    int find(int u){
        
        while(u != parent[u])
            u = parent[u] ;
        
        return u ;
    }
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
       for(int i = 0 ;i <= n ; i++){
           parent.push_back(i) ;
       }
        
        int extra_edges = 0 , c =0 ;
        
        for(int i = 0 ; i < connections.size() ; i++){
            
            int g1 = find( connections[i][0]) ;
            int g2 = find( connections[i][1]) ; 
            
            if(g1 == g2) 
             extra_edges++ ;
            else{
                 merge(g1,g2) ;
                 c++ ;
            } 
               
        }
        
       if(extra_edges >= n -(c+1) )
           return  n -(c+1) ;
        
        return -1 ;
        
    }
};