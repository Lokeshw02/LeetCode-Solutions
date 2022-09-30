class ds{
    private :
    int n ;
    vector<int>parent ;
    
    public :
    
    ds(int n ){
        this->n = n ;
        
    parent.push_back(0) ;
    
    for(int i = 1; i <= n ; i++){
        parent.push_back(i) ;
    }
    }
    
    int find(int u){
        
        while(u != parent[u]){
            u = parent[u] ;
        }
        
        return u ;
    }
    
    void merge(int u, int v){
        int g1 = find(u) ;
        int g2 = find(v) ;
        
        parent[v] = u ;
    }
   
    
};



class Solution {
public:   
    
  
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
       int n = edges.size() ; 
       ds uf(n) ; 
        
       for(int i = 0 ; i < n ; i++){
           
           int g1 = uf.find(edges[i][0]) ;
           int g2 = uf.find(edges[i][1]) ;
           
           if(g1 == g2 ) 
               return edges[i] ;
           uf.merge(g1,g2) ;
       } 
         
        return {} ;
    }
};