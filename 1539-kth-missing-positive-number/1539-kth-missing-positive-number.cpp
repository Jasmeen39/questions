class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n= arr.size();
        int no=1;
        vector<int> missing;
        for(int i=0; i<n; i++){
            while(no<arr[i]){
                missing.push_back(no);
                no++;
            }
            no=arr[i]+1;
        }
        // But missing numbers can still exist after array end
        while(missing.size()<k){
            missing.push_back(no);
            no++;
        }
        return missing[k-1];
    }
};