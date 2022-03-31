class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = [0]*len(prices) 
        min_price = prices[0] 
        for i in range(len(prices)):
            dp[i] = max(dp[i-1],prices[i]-min_price)
            min_price = min(min_price,prices[i])
            
        return dp[len(prices)-1]