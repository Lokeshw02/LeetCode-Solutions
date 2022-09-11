class Solution {
public:
    
    int mod = 1e9+7 ;
    
    static bool comp(pair<int,int> &a, pair<int,int> &b){
        
        return a.first > b.first ;
        
        
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>> arr ;
        priority_queue<int,vector<int>, greater<int>> pq ;
        
        for(int i = 0; i < n ; i++){
            arr.push_back({efficiency[i],speed[i]}) ;
            
        }
        
        sort(arr.begin(), arr.end(), comp) ;
        
        long long ans = -1e17 , sum = 0, currAns ;
        
        for(int i = 0; i < n ; i++){
            
          
            
            int mineff = arr[i].first ;
            int newspeed = arr[i].second ;
            
              pq.push(newspeed);
            
            sum += newspeed ;
            
            //Remove the smallest speed 
            
            if(pq.size() > k){
                sum -= pq.top() ;
                pq.pop() ;
            }
            
            currAns = (sum*mineff) ;
            ans = max(ans,currAns) ;
        }
        
        return ans%mod ;
    }
};