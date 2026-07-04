class CountSquares {
public:
unordered_map<int,unordered_map<int,int>>mp; // stores pair and their count
set<vector<int>>pairs;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        
        int x = point[0], y = point[1];
        mp[x][y]++;

        pairs.insert(point);
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];

        int ans = 0;
        for (auto it = pairs.begin(); it != pairs.end(); it++) {

            int r1 = (*it)[0];

            int c1 = (*it)[1];

            // reject same point or flat points

            if (r1 == x || c1 == y) continue;

            // reject non-square diagonal

            if (abs(r1 - x) != abs(c1 - y)) continue;

            // other two corners

            int x2 = x, y2 = c1;

            int x3 = r1, y3 = y;

            if (mp[x2].count(y2) && mp[x3].count(y3)) {

                ans += mp[r1][c1] * mp[x2][y2] * mp[x3][y3];

            }

        }

        return ans;

    }
};
