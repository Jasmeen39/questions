class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int a= 2*nums.size();
        vector<int>ans(a);
        for(int i=0; i<nums.size();i++){
            ans[i]=nums[i];
        }
        for(int i=nums.size(); i<a;i++){
            ans[i]=nums[i-nums.size()];
        }
        return ans;
    }
};