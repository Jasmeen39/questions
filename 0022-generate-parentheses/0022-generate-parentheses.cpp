class Solution {
public:
    vector<string> res;
    bool isvalid(string curr){
        int count=0;
        for(auto x:curr){
            if(x=='(') count++;
            else if (x==')') count--;
            //Imp for ")(" ivalid situation coz count will be 0 but still invalid
            if(count < 0)
            return false;
        }
        if(count==0) return true;
        else return false;
    }
    void solve(int idx, int n, string & curr){
        //Base case
        //Wrong coz if idx=2*n but curr is not valid condition would be false and it will continue 2*n+1, 2*n+2... etc
        // if(idx==2*n  && isvalid(curr)) {res.push_back(curr);
        // return;
        // }
        if(idx==2*n){
            if(isvalid(curr)) res.push_back(curr);
            //now in this case it will always return doesnt matter if curr is valid or not
            return;
        }
        
        //Left: Take open bracket "("
        curr.push_back('(');
        //Explore
        solve(idx+1,n,curr);
        //Undo
        curr.pop_back();

        //Right: Take close bracket ")"
        curr.push_back(')');
        //Explore
        solve(idx+1,n,curr);
        //Undo
        curr.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        string curr= "";
        solve(0,n,curr);
        return res;  
    }
};