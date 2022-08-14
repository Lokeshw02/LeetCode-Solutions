class ds {
    
    public : 
    
    ds(int n){
        num_items = n ;
        num_groups = n ;
        
        for(int i = 0; i < n; i++){
            parent_.push_back(i) ;
        }
    }
    
    int find(int u){
        while(u != parent_[u])
            u = parent_[u] ;
        
        
        return u ;
    }
    
    void union_(int u, int v){
        int g1 = find(u) ;
        int g2 = find(v) ;
    
        parent_[g2] = g1 ;
        num_groups -- ;
        
    }
    
    int getGroupCount(){
        return num_groups ; 
    }
    
    private :
    int num_items ;
    vector<int>parent_ ;
    int num_groups ;   
} ;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        ds uf(n) ;
        int extra_edge = 0 , group_count = 0 ;
        
        for(int i = 0; i< connections.size() ; i++){
            int g1 = uf.find(connections[i][0]) ;
            int g2 = uf.find(connections[i][1]) ;
            
            if(g1 == g2)
                extra_edge++ ;
            else
                uf.union_(connections[i][0], connections[i][1]) ;
        }
        group_count = uf.getGroupCount() ;
        
        if(extra_edge >= group_count -1)
            return group_count -1 ;
        else 
            return -1 ; 
    }
};
