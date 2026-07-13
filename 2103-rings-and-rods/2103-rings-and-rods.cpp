class Solution {
public:
    int countPoints(string rings) {
        int n=rings.size();
        int rgb[]={1,2,4};
        vector<int> v(10);
        for(int i=0;i<n;i+=2){
            char color=rings[i];
            int colorindex=0;
            if(color=='G') colorindex=1;
            else if(color=='B') colorindex=2;
            int rod=rings[i+1]-'0';
            v[rod]=v[rod] | rgb[colorindex];
        }
        int count=0;
        for(auto x:v){
            if(x==7) count++;
        }
        return count;
    }
};