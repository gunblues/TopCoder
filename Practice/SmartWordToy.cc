#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;

class SmartWordToy {
private:
    bool allow[26][26][26][26];
    int dp[26][26][26][26];
public:
    int minPresses(string start, string finish, vector<string> forbid) {
        
        memset(allow, -1, sizeof(allow));
        
        for (int i=0; i<forbid.size(); ++i) {
            vector<string> vs(4);
            istringstream Sin(forbid[i]);
            Sin >> vs[0] >> vs[1] >> vs[2] >> vs[3];
            for (int i=(int)vs[0].length()-1; i>=0; --i)
                for (int j=(int)vs[1].length()-1; j>=0; --j)
                    for (int k=(int)vs[2].length()-1; k>=0; --k)
                        for (int t=(int)vs[3].length()-1; t>=0; --t)
                            allow[vs[0][i]-'a'][vs[1][j]-'a'][vs[2][k]-'a'][vs[3][t]-'a'] = false;
        }
        
        memset(dp, -1, (int)sizeof(dp));
        
        vector<int> cur;
        cur.push_back(start[0]-'a');
        cur.push_back(start[1]-'a');
        cur.push_back(start[2]-'a');
        cur.push_back(start[3]-'a');
       
        queue<vector<int>> Q;
        Q.push(cur);
        dp[cur[0]][cur[1]][cur[2]][cur[3]] = 0;
        
        while (!Q.empty()) {
            cur = Q.front();
            Q.pop();
            for (int k=0; k<4; ++k) {
                vector<int> d = cur;
                for (d[k] = cur[k]-1; d[k] <= cur[k]+1; ++d[k]) {
                    int tmp = d[k];
                    if (tmp < 0 || tmp >= 26) {
                        d[k] = (d[k] + 26) % 26;
                    }
                    if (dp[d[0]][d[1]][d[2]][d[3]] == -1 && allow[d[0]][d[1]][d[2]][d[3]]) {
                        dp[d[0]][d[1]][d[2]][d[3]] = dp[cur[0]][cur[1]][cur[2]][cur[3]] + 1;
                        
                        if (d[0] == finish[0]-'a' && d[1] == finish[1]-'a' && d[2] == finish[2]-'a' && d[3] == finish[3]-'a') {
                            return dp[d[0]][d[1]][d[2]][d[3]];
                        }
                        
                        Q.push(d);
                    }
                    d[k] = tmp;
                }
            }
        }
        return dp[finish[0]-'a'][finish[1]-'a'][finish[2]-'a'][finish[3]-'a'];
    }
};

int main(int argc, const char * argv[]) {
    
    SmartWordToy swt;
    
    cout << swt.minPresses("aaaa", "zzzz", {"a a a z", "a a z a", "a z a a", "z a a a", "a z z z", "z a z z", "z z a z", "z z z a"}) << endl;
    cout << swt.minPresses("aaaa", "bbbb", {}) << endl;
    cout << swt.minPresses("aaaa", "mmnn", {}) << endl;
    cout << swt.minPresses("aaaa", "zzzz", {"bz a a a", "a bz a a", "a a bz a", "a a a bz"}) << endl;
    cout << swt.minPresses("aaaa", "zzzz",
                           {"cdefghijklmnopqrstuvwxyz a a a",
                               "a cdefghijklmnopqrstuvwxyz a a",
                               "a a cdefghijklmnopqrstuvwxyz a",
                               "a a a cdefghijklmnopqrstuvwxyz"}) << endl;
    cout << swt.minPresses("zzzz", "aaaa",
                           {"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
                               "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk"}) << endl;
    

    return 0;
}

