class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}
        res = []
        for i in range(len(nums)):
            if target - nums[i] in dict :
                res.append(dict[target - nums[i]])
                res.append(i)
                
            
            else:
                dict[nums[i]] = i
    
                
        return res 
        
        