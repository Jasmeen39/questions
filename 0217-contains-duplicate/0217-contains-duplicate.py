class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        set1=set(nums)
        return len(set1)!=len(nums)
        