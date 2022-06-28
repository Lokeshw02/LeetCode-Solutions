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
        else if(target<0)
            return;
        
        else if(i==n)
            return;
        curr.push_back(nums[i]);
        solve(i, nums, target-nums[i]);
        curr.pop_back();
        solve(i+1, nums, target);
    }
    
    void solve();
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        solve(0, nums, target);
        return vector<vector<int>>(res.begin(), res.end());
    }
};