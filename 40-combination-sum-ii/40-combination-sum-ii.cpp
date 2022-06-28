class Solution {
public:
    set<vector<int>>res;
    vector<int>curr;
    void solve(int i, vector<int>&nums, int target){
        int n = nums.size();
        if(target==0){
            res.insert(curr);
            return;
        }    
        if(target<0)
            return;
        if(i==n)
            return;
        curr.push_back(nums[i]);
        solve(i+1, nums, target-nums[i]);
        curr.pop_back();
        int j=i+1;
        while(j<n && nums[j]==nums[i] )
            j++;
        solve(j, nums, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
       // cout << n<<endl;
        sort(nums.begin(), nums.end());
        solve(0, nums, target);
        return vector<vector<int>>(res.begin(), res.end());
    }
};