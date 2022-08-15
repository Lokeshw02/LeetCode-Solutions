class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dp(n, vector<int>(n,INT_MAX)) ; 
        //Intialise 
        for(auto & edge : edges ){
            dp[edge[0]][edge[1]] = edge[2] ;
             dp[edge[1]][edge[0]] = edge[2] ;
        }
        
        for(int i = 0 ;i <n ; i++)
            dp[i][i] = 0 ;
            //Bottom up dp 
            
            for(int k = 0; k< n ; k++){
                for(int i = 0; i<n ; i++){
                    for(int j = 0; j<n ; j++){
                        if(dp[i][k] == INT_MAX || dp[k][j] == INT_MAX)
                            continue ;
                        dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]) ;
                    }
                }
            }
        
        //By now I have the smallest part 
        int count, min_count = INT_MAX, city ;
        
        for(int i = 0; i<n ; i++){
            count =  0 ;
            for(int j= 0 ; j <n ;j++){
                if(dp[i][j] <= distanceThreshold)
                    count++ ;
            }
            if(count <= min_count){
                min_count = count ;
                city = i ;
            }
        }
        
        return city ;
    }
};