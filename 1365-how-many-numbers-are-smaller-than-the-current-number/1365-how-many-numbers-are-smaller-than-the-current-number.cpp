class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
                          //Brute force
     // int n = nums.size();
    //     vector<int> counts;
    //    int count=0;
    //     for(int i=0; i<n; i++){
           
    //       for(int j=0; j<n; j++){
    //         if(i!=j && nums[j]<nums[i]){
    //             count++;
    //         }
    //        } 
    //        counts.push_back(count);
    //        count=0;
    //     }
    //     return counts; 

                          // Optmal
       int n= nums.size();
       vector<int> temp= nums;
       sort(temp.begin(),temp.end());
        unordered_map<int,int> mpp;
        
        for(int i=0; i<n; i++){
            if(mpp.find(temp[i])==mpp.end())
            mpp[temp[i]]=i;
        } 

        vector<int> ret;
        for(int i=0; i<n; i++){
            ret.push_back(mpp[nums[i]]);
        }   
        return ret;               
    }
};