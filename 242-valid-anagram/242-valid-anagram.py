class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        str1 = "".join(sorted(t)) 
        str2 = "".join(sorted(s)) 
        
        return str1 == str2
        