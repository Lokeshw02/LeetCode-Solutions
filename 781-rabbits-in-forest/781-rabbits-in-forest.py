class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        
        
        n = len(answers) 
        m = {}
        for i in range(n):
            if answers[i] not in m:
                m[answers[i]] = 1
                
            else :
                m[answers[i]] += 1 
                
        res = 0 
        
        for key,value in m.items() :
            k = key 
            v = value 
            
            res += ((ceil)(v/(k+1))*(k+1))
            
            
        return res 
        
            