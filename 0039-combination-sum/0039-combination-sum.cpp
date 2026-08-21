class Solution {
public:
    vector<vector<int>>res;
    vector<int> temp;
    bool valid (int target){
        int n=temp.size();
        int sum=0;
        for(auto x:temp){
            sum+=x;
        }
        return sum==target;
    }
    void solve(vector<int>& candidates, int target, int start){
                              //Base Case
        //if(valid(target)){
         if(target==0){
            res.push_back(temp);
            return;
        }
        //Do something
        for(int i=start; i<candidates.size(); i++){ //Not i=0 to prevent duplications
            if(candidates[i]>target) continue;
            //Explore
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i);
            //Undo
            temp.pop_back();
            //Do something
            //solve(candidates,target-candidates[i],i); (Dont need this)
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates,target,0);
        return res;
    }
};