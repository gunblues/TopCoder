#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

#define BOUND_ROW 55
#define BOUND_COL 55

class WalkingHome {
private:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    char ch[4]={'-','-','|','|'};
 
    bool in_bound(int x, int y, const vector<string> &map) {
        if (x >= 0 && x < map.size() && y >= 0 && y < map[0].size()) {
            return true;
        }
        
        return false;
    }
public:
    int fewestCrossings(vector<string> map) {

        int crossCount[BOUND_ROW][BOUND_COL];
        memset(crossCount, 0, sizeof(crossCount));
        
        int sx=0, sy=0, hx=0, hy=0;
        for (int i=0;i<map.size();i++) {
            for (int j=0;j<map[0].size();j++) {
                if (map[i][j] == 'S') {
                    sx = i;
                    sy = j;
                    map[i][j] = '.';
                }
                else if (map[i][j] == 'H') {
                    hx = i;
                    hy = j;
                    map[i][j] = '.';
                }
            }
        }
        
        for (int i=0;i<map.size();i++)
            cout << map[i] << endl;
        
        queue<pair<int, int>> q;
        q.push(make_pair(sx, sy));
        
        for (int i=0;i<map.size();i++)
            for (int j=0;j<map[0].size();j++)
                crossCount[i][j]=2000000000;
        
        crossCount[sx][sy] = 0;
        
        while (!q.empty()) {
            pair<int, int> tmp = q.front();
            
            int curX = tmp.first;
            int curY = tmp.second;
            
            q.pop();
            
            cout << "curX:" << curX << ",curY:" << curY << endl;
            
            for (int i=0; i<4; i++) {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];
                
                if (curX == 1 && curY == 4) {
                    int asdf = 0;
                }
                
                if (in_bound(nextX, nextY, map)) {
                    int cross = 0;
                    
                    //need to find next position which is capable of walking
                    while (map[nextX][nextY]==ch[i]) {
                        nextX+=dx[i];
                        nextY+=dy[i];
                        cross=1;
                    }
                    
                    if (map[nextX][nextY]=='.') {
                        //如果下一點穿越的街道大於現在街道+穿越的街道，代表在目前路徑中下一點還沒走過
                        if (crossCount[nextX][nextY]>crossCount[curX][curY]+cross) {
                            crossCount[nextX][nextY]=crossCount[curX][curY]+cross;
                            q.push(make_pair(nextX,nextY));
                            cout << "    nextX:" << nextX << ",nextY:" << nextY << ",crossCount:" << crossCount[nextX][nextY] << endl;
                        }
                    }
                }
            }
            cout << "    ----4 direction tried-----" << endl;
            
        }

        if (crossCount[hx][hy]==2000000000) {
            cout << -1 << endl;
            return -1;
        }
        cout << crossCount[hx][hy] << endl;
        return crossCount[hx][hy];
    }
};

int main(int argc, const char * argv[]) {
    WalkingHome wh;
    
    wh.fewestCrossings({
        "S.|..",
        "..|.H"});
    
    
    wh.fewestCrossings({
        "S.|..",
        "..|.H",
        "..|..",
        "....."});
    
    wh.fewestCrossings({
        "S.||...",
        "..||...",
        "..||...",
        "..||..H"});
    wh.fewestCrossings({
        "S.....",
        "---*--",
        "...|..",
        "...|.H"});
    wh.fewestCrossings({
        "S.F..",
        "..F..",
        "--*--",
        "..|..",
        "..|.H"});
    
    wh.fewestCrossings({
        "H|.|.|.|.|.|.|.|.|.|.|.|.|.",
        "F|F|F|F|F|F|F|F|F|F|F|F|F|-",
        "S|.|.|.|.|.|.|.|.|.|.|.|.|."});
    
    
    wh.fewestCrossings({
        "S-H"});
    
    return 0;
}


