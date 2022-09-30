class ds{
    private :
    int total ;
    vector<int>parent; 
    int num_groups ;
    
    public :
    
     ds(int n){
        total = n ;
        num_groups = n ;
        
        for(int i = 0 ; i < n ; i++){
            parent.push_back(i) ;
        }
    }
    
    int find(int u ){
        while(u != parent[u]){
            u = parent[u] ;
        }
        
        return u ;
    }
    
    void merge(int u, int v){
        int g1 = find(u) ;
        int g2 = find(v) ;
        
        parent[g2] = g1 ;
        num_groups-- ;
    }
    
    int getnum_groups(){
        return num_groups ;
    }
};



class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        ds uf(n) ;
        int extra_edge = 0, num_of_groups = 0 ;
        
        for(int i = 0 ; i < connections.size() ; i++){
            
            int g1 = uf.find(connections[i][0]) ;
            int g2 = uf.find(connections[i][1]) ;
            
            if(g1 == g2 )
                extra_edge++ ;
            else
                uf.merge(g1,g2) ;
                
        }
        num_of_groups = uf.getnum_groups() ;
        
        return extra_edge >= num_of_groups -1 ? num_of_groups -1 : -1 ;
        
    }
};