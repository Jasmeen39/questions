class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int i=0; i<arr.size();i++){
            mpp[arr[i]]++;
        }
        unordered_set<int>st;
        //Please remember syntax of  map, set etc. Where to use insert, second, delete, erase etc
        for(auto it: mpp){
            if(st.find(it.second)!=st.end()) return false;
            st.insert(it.second);
        }
        return true;
    }
};