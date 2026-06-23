class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxones=0;
        //int l=0, r=0;
        int count=0;
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                count++;
                maxones=max(maxones,count);
                //r++;
            }
            else if(nums[i]==0){
                count=0;
                // while(nums[r]==0){
                //     r++;
                // }
                // l=r;
            }
        }
        return maxones;
    }
};