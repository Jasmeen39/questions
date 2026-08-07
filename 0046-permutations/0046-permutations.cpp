class Solution {
public:
    vector<vector<int>> res;
    unordered_set<int> st;
    int n;
    void solve(vector<int>& nums,vector<int>& temp){
            //Base case
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
    void solve2(int idx, vector<int>& nums){ //Dont use & in idx
           //Base case
        if(idx==n){
            res.push_back(nums);
            return;
        }
        for(int i=idx; i<n; i++){
            //Do
            swap(nums[i],nums[idx]);
            //Explore
            solve2(idx+1,nums);
            //Undo
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        //vector<int> temp;
            //No need to pass index(i) as we gonna start from the starting index anyways
        //solve(nums,temp);
        solve2(0, nums);
        return res;
    }
};