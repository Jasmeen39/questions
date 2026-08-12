class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int idx=1;
        int sum=nums[0];
        while(idx<n){
            if(nums[idx]!=nums[idx-1]+1) break;
            sum=sum+nums[idx];
            idx++;
        }
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<n){
            if(nums[i]<sum) i++;
            else if(nums[i]==sum){
                sum++;
                i++;
            }
            else break;
        }
        return sum;
    }
};