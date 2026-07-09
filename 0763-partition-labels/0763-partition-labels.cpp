class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int> last;
        int n=s.size();
        for(int i=0; i<n; i++){
            last[s[i]-'a']=max(last[s[i]-'a'],i);
        }
        int i=0;
        int j=0;
        int end=0;
        vector<int> res;
        while(i<n){
            end=max(last[s[i]-'a'],j);
            while(j!=end){
                j++;
                end=max(last[s[j]-'a'],end);
            }
            res.push_back(j-i+1);
            i=j+1;
        }
        return res;
    }
};