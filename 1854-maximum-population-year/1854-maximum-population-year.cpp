class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>> events;
        for(auto log:logs){
            events.push_back({log[0],+1});
            events.push_back({log[1],-1});
        }
        sort(events.begin(),events.end());
        int currpop=0;
        int maxpop=0;
        int minyear=2050;
        for(auto e:events){
            currpop+=e.second;
            if(currpop>maxpop){
                maxpop=currpop;
                minyear=e.first;
            }
        }
        return minyear;
    }
};