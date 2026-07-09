class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<int> leftview(n);
        vector<int> topview(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                leftview[i]=max(leftview[i],grid[i][j]);
                topview[i]=max(topview[i],grid[j][i]);
            }
        }
        int result=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                result+=min(leftview[i],topview[j])-grid[i][j];
            }
        }
        return result;
    }
};