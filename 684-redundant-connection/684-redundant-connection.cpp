class ds{
    public :
    
    ds(int n ){
        this->n = n ;
        //1 indexing dummy 
        parent.push_back(0) ;
        
        for(int i =1 ; i<= n ;i++){
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
        
        parent[g2] = g1 ;
        
       
    }
    
     private :
        
        int n ;
        vector<int>parent ;
};




class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() ;
        ds uf(n) ;
        
        for(int i =0 ; i< n ; i++){
            int g1 = uf.find(edges[i][0]) ;
            int g2 = uf.find(edges[i][1]) ;
            
            if(g1 == g2 ) return edges[i] ;
            
            uf.merge(edges[i][0], edges[i][1]) ;
        }
        
        return {} ;
    }
};