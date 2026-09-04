class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict={}
        for i,x in enumerate (nums):
            more=target-x
            if more in dict : return [dict[more],i]
            else: dict[x]=i
        