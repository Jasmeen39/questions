class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> count(26,0);
       for(auto ch: s){
        count[ch-'a']++;
       }
       for(auto ch:t){
        count[ch-'a']--;
       }
       for(auto it: count){
        if(it!=0) return false;
       }
       return true;
    }
};