class Solution {
public:
     vector<int>parent ;
    
    void merge(int u, int v){
        
        int g1 = find(u) ;
        int g2 = find(v) ;
        
        parent[g2] = g1 ;
    }
    
    int find(int u){
        
        while(u != parent[u]){
            u = parent[u] ;
        }
        
        return u ;
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size() ;
       
        parent.push_back(0) ;
        
        for(int i = 1 ; i <= n ; i++){
            parent.push_back(i) ;
        }
        
        
        for(int i = 0 ; i< n ; i++ ){
            
            int g1 = find(edges[i][0]) ;
             int g2 = find(edges[i][1]) ; 
            
            if(g1 == g2 ) 
                return edges[i] ;
            
            merge(g1,g2) ;
        }
        
        return {} ;
     }
};