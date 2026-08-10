class Solution {
public:
    vector<vector<int>> res;
    void solve(int idx,vector<int>nums, vector<int> & temp){
        //Base case
        if(idx==nums.size()){
            res.push_back(temp);
            return;
        }
             //Left: Choose nums[idx]
        temp.push_back(nums[idx]);
        //Explore next element
        solve(idx+1,nums,temp);

             //Undo
        temp.pop_back();

             //Right: Don't choose nums[idx]
        solve(idx+1,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0,nums,temp);
        return res;
    }
};