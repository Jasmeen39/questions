class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> arr;
        int n=0;
        if(x<0) return false;
        while(x!=0){
            n=x%10;
            arr.push_back(n);
            x/=10;
        }
        int count=0;
        int size=arr.size();
        for(int i=0; i<size/2;i++){
            if(arr[i]==arr[size-1-i]) count++;
        }
        if(count==size/2) return true;
        return false;
    }
};