class Solution {
public:
    int numSplits(string s) {
        int n=s.size();
        vector<int> left(26,0);
        vector<int> right(26,0);
        int leftdis=0;
        int rightdis=0;
        int ways=0;
        //first move everything in right 
        for(char x: s){
            if(right[x-'a']==0) rightdis++;
            right[x-'a']++;
        }
        //Now start the logic, start from first index and puting it in left
        for(int i=0; i<n; i++){
            char c=s[i];
            //Add c to left
            if(left[c-'a']==0) leftdis++;
            left[c-'a']++;
            //remove c from right
            right[c-'a']--;
            //if after removing c the freq of that particular char becomes zero it means is doesnt exist in right anymore and we can decrease rightdis
            if(right[c-'a']==0) rightdis--;
            if(leftdis==rightdis) ways++;
        }
        return ways;
    }
};