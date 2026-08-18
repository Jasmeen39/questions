class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>ans(n,-1);
        for(int startcol=0; startcol<n; startcol++){
            int col=startcol;
            for(int row=0; row<m; row++){
                //Ball wants to move right
                if(grid[row][col]==1){
                    //curr col is rightmost or next element is left(V)
                    if(col==n-1 || grid[row][col+1]==-1){
                        col=-1;
                        break;
                    }
                    col=col+1;
                }
                //Ball wants to move left
                else{
                    //curr col is lefttmost or previous element is right(V)
                    if(col==0 || grid[row][col-1]==1){
                        col=-1;
                        break;
                    }
                    col=col-1;
                }
            }
            ans[startcol]=col;
        }
        return ans;
    }
};