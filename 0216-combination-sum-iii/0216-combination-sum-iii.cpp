class Solution {
public:
    vector<vector<int>> res;
    vector<int>temp;
    bool valid(vector<int>temp,int n){
        int sum=0;
        for(auto x:temp){
            sum+=x;
        }
        return sum==n;
    }
    void solve(int elt, int k, int n){
        //Base case
        if(temp.size()==k){
            if(valid(temp,n))
            res.push_back(temp);
            return;
        }
        if(elt > 9)
            return;
        //Do something
        temp.push_back(elt);
        //Explore
        solve(elt+1, k, n);
        //Undo
        temp.pop_back();
        //Explore
        solve(elt+1,k,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       solve(1,k,n);
       return res; 
    }
};