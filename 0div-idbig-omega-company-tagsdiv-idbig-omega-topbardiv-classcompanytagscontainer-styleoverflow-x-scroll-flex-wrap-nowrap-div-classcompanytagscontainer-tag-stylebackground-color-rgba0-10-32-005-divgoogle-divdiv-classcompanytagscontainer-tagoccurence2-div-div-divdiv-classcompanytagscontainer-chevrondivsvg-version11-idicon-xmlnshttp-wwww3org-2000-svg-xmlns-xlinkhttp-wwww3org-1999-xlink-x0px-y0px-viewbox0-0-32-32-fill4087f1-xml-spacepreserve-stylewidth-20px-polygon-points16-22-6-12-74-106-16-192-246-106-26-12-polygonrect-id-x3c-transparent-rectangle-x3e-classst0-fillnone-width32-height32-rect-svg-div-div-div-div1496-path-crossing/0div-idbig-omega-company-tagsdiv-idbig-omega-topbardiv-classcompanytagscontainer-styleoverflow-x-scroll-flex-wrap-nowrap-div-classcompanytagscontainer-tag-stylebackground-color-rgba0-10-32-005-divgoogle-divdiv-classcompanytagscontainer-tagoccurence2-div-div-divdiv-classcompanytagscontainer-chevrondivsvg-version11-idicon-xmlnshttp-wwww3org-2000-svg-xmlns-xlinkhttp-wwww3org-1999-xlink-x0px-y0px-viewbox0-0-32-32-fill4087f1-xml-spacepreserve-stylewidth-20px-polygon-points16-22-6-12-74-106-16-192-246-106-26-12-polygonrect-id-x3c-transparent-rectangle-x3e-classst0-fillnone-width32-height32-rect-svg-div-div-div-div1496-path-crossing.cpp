class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> vis;
        int x = 0, y = 0;
        vis.insert({x,y});
        for(auto c : path){
            if(c == 'N') x++;
            else if(c=='E') y++;
            else if(c=='W') y--;
            else x--;
            if(vis.find({x,y}) != vis.end())
                return true;
            vis.insert({x,y});
        }
        return false;
    }
};