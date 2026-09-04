class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict1={}
        for x in s:
            if x in dict1: dict1[x]+=1
            else: dict1[x]=1
        for x in t:
            if x in dict1: dict1[x]-=1
            else: return False
        for x in dict1:
            if dict1[x] is not 0: return False
        return True