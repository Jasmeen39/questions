class Solution {
public:
    int mySqrt(int x) {
        int low=1;
        int high=x;
        long long mid;
        int res=x;
        while(low<=high){
            mid=low+(high-low)/2;
            if(mid*mid<=x){
                res=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return res;
    }
};