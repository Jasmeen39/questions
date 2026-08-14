class Solution {
public:
    //set<int> visited;
    // void dfs(int room, vector<vector<int>>& rooms){
    //     visited.insert(room);
    //     for(auto key: rooms[room]){
    //         if(visited.find(key)==visited.end()) dfs(key,rooms);
    //     }
    // }
    void dfs(int room,vector<vector<int>>& rooms,vector<bool> & vis ){
        vis[room]=true;
        for(auto key:rooms[room]){
            if(!vis[key]) dfs(key,rooms,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
    //    dfs(0,rooms);
    //    return visited.size()==rooms.size();
    int n=rooms.size();
    vector<bool>vis(n,0);
    dfs(0,rooms,vis);
    for(int i=0; i<n; i++){
        if(!vis[i]) return false;
    }
    return true;
    }
};