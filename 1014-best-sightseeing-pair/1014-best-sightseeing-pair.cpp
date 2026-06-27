class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxLeft = values[0]; // Initialize with the first value + 0
    int maxScore = INT_MIN; // Initialize maxScore with the smallest integer
    
    for (int j = 1; j < values.size(); ++j) {
        // Calculate score for the current pair
        maxScore = max(maxScore, maxLeft + values[j] - j);
        // Update maxLeft
        maxLeft = max(maxLeft, values[j] + j);
    }
    
    return maxScore;
    }
};