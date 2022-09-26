typedef long long ll;
class Solution {
   public:
    // get sum of subarray using prefix sum array
    ll getSumRange(vector<ll>& vec, int l, int r) {
        if (l == -1) return vec[r - 1];
        return vec[r - 1] - vec[l];
    }
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        //find index of nearest smaller element to the left
        vector<int> left(n, -1);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            if (!s.empty())
                left[i] = s.top();
            s.push(i);
        }
        //clear stack
        while (!s.empty()) s.pop();
        //find index of nearest smaller element to the right
        vector<int> right(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            if (!s.empty())
                right[i] = s.top();
            s.push(i);
        }
        //generate prefix array
        vector<ll> prefix(n);
        for (int i = 0; i < n; i++)
            if (i == 0)
                prefix[i] = nums[i];
            else
                prefix[i] = nums[i] + prefix[i - 1];
        //generate answer
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll val = (ll)nums[i] * (ll)(getSumRange(prefix, left[i], right[i]));
            ans = max(ans, val);
        }
        return int(ans % int(1e9 + 7));
    }
};