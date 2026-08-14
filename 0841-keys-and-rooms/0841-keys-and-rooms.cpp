class Solution {
public:
    set<int> visited;
    void dfs(int room, vector<vector<int>>& rooms){
        visited.insert(room);
        for(auto key: rooms[room]){
            if(visited.find(key)==visited.end()) dfs(key,rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       dfs(0,rooms);
       return visited.size()==rooms.size();
    }
};