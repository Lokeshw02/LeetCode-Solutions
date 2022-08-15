class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
    //Adjecency Lists 
        vector<vector<pair<int,int>>> graph(n) ;
        
        for(int i = 0; i< flights.size(); i++){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]}) ;
        }
        
        //Modification of Dijkasta 
        //pq -> {weight, node#, level}
        
        
        priority_queue< vector<int> , vector<vector<int>>, greater<vector<int>> > pq ;
        
        vector<int> dis(n,INT_MAX);
        
        pq.push({0,src,0}) ;
        
        while(!pq.empty()){
            vector<int> t = pq.top() ;
            pq.pop() ;
            
            if(t[2] > k+1 || t[2] >= dis[t[1]]) continue ;
            
            if(t[1] == dst) return t[0] ;
            
            dis[t[1]] = t[2];
            //ELse push the neighbours 
            
            for(auto &nbr :  graph[t[1]]){
                pq.push({t[0] + nbr.second,nbr.first, t[2]+1}) ;
                
            }

        }
        
        return -1 ;
    }
};