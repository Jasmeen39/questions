class Solution {
public:
    vector<vector<int>> res;
    unordered_set<int> st;
    int n;
    void solve(vector<int>& nums,vector<int>& temp){
        if(temp.size()==n){ 
            res.push_back(temp);
            return;}
        for(int i=0; i<n; i++){
            if(st.find(nums[i])==st.end()){
                //Do
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                //Explore
                solve(nums,temp);
                //Undo
                temp.pop_back();
                st.erase(nums[i]); //Not temp[i]
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<int> temp;
        //No need to pass index(i) as we gonna start from the starting index anyways
        solve(nums,temp);
        return res;
    }
};