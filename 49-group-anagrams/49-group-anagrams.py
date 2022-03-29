class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        m ={} 
        res = []
        gId = "" 
        
        for i in range(len(strs)):
            gId = strs[i]
            gId = ''.join(sorted(gId)) 
            
            
            if gId in m:
                res[m[gId]].append(strs[i]) 
                
            else :
                res.append([]) 
                res[len(res) -1].append(strs[i])
                
                m[gId] = len(res) -1 
                
                
        return res 
        
        
        