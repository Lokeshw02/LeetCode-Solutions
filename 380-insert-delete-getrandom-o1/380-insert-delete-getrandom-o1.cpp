class RandomizedSet {
public:
    
    unordered_map<int,int> m ;
    vector<int>arr ;
    
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
    if(m.find(val) != m.end()) return false ;
      
        
    
        arr.push_back(val) ;
        m[val] = arr.size()-1 ;
        
        return true ;
   
    }
    
    bool remove(int val) {
        
        if(m.find(val) == m.end() ) return false ;
    
        int lastNum = arr.back() ;
        
//          m[lastNum] = m[val] ;
        
//         arr[m[val]] = lastNum ;
        
        swap(arr[arr.size()-1],arr[m[val]]) ;
        
         m[lastNum] = m[val];
        
       
        
        arr.pop_back() ;
        m.erase(val) ;
        return true ;
    }
    
    int getRandom() {
        
        int randNum = rand()%arr.size() ;
        
        return arr[randNum] ;
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */