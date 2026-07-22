class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set (nums.begin(),nums.end());
        int n= nums.size();
        int s= set.size();
        if(n==s) return false;
        return true;
    }
};