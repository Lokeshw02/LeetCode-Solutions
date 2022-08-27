class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int rows = matrix.size(), cols = matrix[0].size() ;
        int res  = INT_MIN ;
        
        for(int l = 0 ; l < cols; l++){
            vector<int>sums(rows) ;
            for(int r = l; r < cols ; r++){
                for(int i = 0; i < rows ; i++){
                    sums[i] += matrix[i][r] ;
                }
                set<int> s = {0} ;
                int runsum = 0 ;
                for(int sum : sums){
                    runsum += sum ;
                    auto it = s.lower_bound(runsum-k) ;
                    if(it != s.end())
                        res = max(res,runsum -*it) ;
                    s.insert(runsum) ;
                }
            }
            
        }
        return res ;
        
    }
};