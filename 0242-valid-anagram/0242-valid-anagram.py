class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict1={}
        dict2={}
        for x in s:
            if x in dict1: dict1[x]+=1
            else: dict1[x]=1
        for x in t:
            if x in dict2: dict2[x]+=1
            else: dict2[x]=1
        return dict1==dict2