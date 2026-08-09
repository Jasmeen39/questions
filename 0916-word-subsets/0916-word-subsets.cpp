

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> maxFreq; 
        
        
        for (string& word : words2) {
            unordered_map<char, int> freq;
            for (char c : word) {
                freq[c]++;
            }
            for (auto& [ch, count] : freq) {
                maxFreq[ch] = max(maxFreq[ch], count);
            }
        }
        
        
        vector<string> result;
        for (string& word : words1) {
            unordered_map<char, int> freq;
            for (char c : word) {
                freq[c]++;
            }
            
            bool isUniversal = true;
            for (auto& [ch, count] : maxFreq) {
                if (freq[ch] < count) {
                    isUniversal = false;
                    break;
                }
            }
            
            if (isUniversal) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};
