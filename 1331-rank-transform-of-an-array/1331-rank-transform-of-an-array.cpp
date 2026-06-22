class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mpp;
        int n=arr.size();
        vector<int> temp=arr;
        int count=1;
        sort(arr.begin(),arr.end());
        for(int  i=0; i<n;i++){
            if(mpp.find(arr[i])==mpp.end()) {mpp[arr[i]]=count;
            count++;}
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(mpp[temp[i]]);
        }
        return ans;
    }
};