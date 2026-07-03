class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int prefLength = pref.length();

        for (string& word : words) {
            bool isPrefix = true;
            for (int i = 0; i < prefLength; i++) {
                // Check if the word is shorter than the prefix or mismatches at any point
                if (i >= word.length() || word[i] != pref[i]) {
                    isPrefix = false;
                    break;
                }
            }
            if (isPrefix) count++;
        }

        return count;
    }
};
