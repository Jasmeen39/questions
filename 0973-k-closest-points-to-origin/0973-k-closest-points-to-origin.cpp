class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        //map<int,int> mpp; //(dist,i) //INstead of unordered_map use map to get in sorted manner based on first element
        //Actually even instead of map<int,int> mpp because if two points have same dist from the origin, it will get overwrite
        map<int,vector<int>> mpp;
        int n=points.size();
        for(int i=0; i<n; i++){
            int x=points[i][0];
            int y=points[i][1];
            //int dist=sqrt(pow(x,2)+pow(y,2));
            int dist=x*x+y*y; //As oerdering would be same so dont even need sqrt
            //mpp[dist]=i;
            mpp[dist].push_back(i);
        }
        // for(int j=0; j<k; j++){
        //     res.push_back(points[mpp[dist]]);
        // }
        for(auto it : mpp) {
            for(int index : it.second) {
                res.push_back(points[index]);
                if(res.size() == k)
                    return res;
            }
        }
        return res;
    }
};