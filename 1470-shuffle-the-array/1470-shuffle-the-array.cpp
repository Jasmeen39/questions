class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
      vector<int> temp(nums.size());  
      int index=0;
      for(int i=0; i<n;i++){
        temp[index]=nums[i];
        temp[index+1]=nums[i+n];
        index+=2;
      }
      return temp;
    }
};