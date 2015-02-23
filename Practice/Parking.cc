//
//  Parking.h
//  TopCoder
//
//  Created by hsiao kevin on 2015/2/22.
//  Copyright (c) 2015年 hsiao kevin. All rights reserved.
//
/*
 
 Problem Statement
     
 In a parking lot there are a lot of cars and parking spots and all cars want to drive to a parking spot. Due to the traffic regulations cars may only drive parallel to the boundaries of the parking lot and only at the speed of one square per unit of time.  Usually all cars drive to the nearest available parking spot, but that might turn out badly for some cars. Consider for example the following car park
 .C.....P.X...
 XX.......X..P
 XX.....C.....
 (here 'C' stands for car, 'P' for parking spot, 'X' for wall and '.' for empty spot)  If the car on the bottom drives to its nearest parking spot, the upper left car must drive all the way to the right, taking 13 units of time. If, however, the car on the bottom drives to the parking spot on the right, it will take 6 units of time for both cars to find a parking spot.  Return the minimal amount of time it takes before every car can have a parking spot (assuming that the cars act socially like above). All cars start on an empty spot. Cars are small and any number of them can drive on the same square simultaneously. They can drive over empty spots and parking spots, but not through walls. Each car has to end on a separate parking spot.  If it is impossible for each car to drive to a parking place, return -1.
 Definition
     
 Class:
 Parking
 Method:
 minTime
 Parameters:
 vector <string>
 Returns:
 int
 Method signature:
 int minTime(vector <string> park)
 (be sure your method is public)
 Limits
     
 Time limit (s):
 2.000
 Memory limit (MB):
 64
 Constraints
 -
 park will contain between 1 and 50 elements, inclusive.
 -
 All elements of park have equal length.
 -
 Each element of park has length between 1 and 50, inclusive.
 -
 Each character in park is either 'C', 'P', 'X' or '.'.
 -
 There will be no more than 100 cars and 100 parking places in park.
 Examples
 0)
 
     
 {"C.....P",
 "C.....P",
 "C.....P"}
 Returns: 6
 Every car just drives to the opposite parking spot.
 1)
 
     
 {"C.X.....",
 "..X..X..",
 "..X..X..",
 ".....X.P"}
 Returns: 16
 The slalom takes the car 16 units of time.
 2)
 
     
 {"XXXXXXXXXXX",
 "X......XPPX",
 "XC...P.XPPX",
 "X......X..X",
 "X....C....X",
 "XXXXXXXXXXX"}
 Returns: 5
 This would take 11 instead of 5 units of time if the car on the bottom drove to its nearest parking spot.
 3)
 
     
 {".C.",
 "...",
 "C.C",
 "X.X",
 "PPP"}
 Returns: 4
 While driving, the cars can be on the same empty spot or parking spot, but they have to finish on different parking spots.
 4)
 
     
 {"CCCCC",
 ".....",
 "PXPXP"}
 Returns: -1
 There are not enough parking spots for all the cars.
 5)
 
     
 {"..X..",
 "C.X.P",
 "..X.."}
 Returns: -1
 The car can't reach the parking spot.
 This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

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

class Parking {
private:
    vector<int> dx = {0, 0, 1, -1};    
    vector<int> dy = {1, -1, 0, 0};
    vector<vector<char>> area;
    vector<pair<int, int>> cars;
    vector<pair<int, int>> parkingSlot;
    map<string, int> carsToParking;
    int columnWidth;
    int rows;

    void init(vector <string> park) {
        area.clear();
        carsToParking.clear();
        parkingSlot.clear();
        cars.clear();
        
        columnWidth = (int)park[0].size();
        rows = (int)park.size();
        for (int i=0; i<rows; i++) {
            istringstream iss(park[i]);
            vector<char> v(columnWidth);
            for (int j=0; j<columnWidth; j++) {
                iss >> v[j];
                switch (v[j]) {
                    case 'C':
                        cars.push_back(make_pair(i, j));
                        break;
                    case 'P':
                        parkingSlot.push_back(make_pair(i,j));
                        break;
                }
            }
            area.push_back(v);
        }
    }
    
    bool inBound(int x, int y) {
        if (x >=0 && x < rows && y >=0 && y < columnWidth) {
            return true;
        }
        
        return false;
    }

    int getDistance(int x, int y, int px, int py) {
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        
        vector<vector<char>> visted = area;
        vector<vector<int>> sd(rows);
        for(int i=0; i<sd.size(); i++) {
            vector<int> v(columnWidth);
            sd[i] = v;
        }
        
        visted[x][y] = 'V';

        while (!q.empty()) {
            pair<int, int> tmp = q.front();
            q.pop();
            
            for (int i=0; i<4; i++) {
                if (inBound(tmp.first + dx[i], tmp.second + dy[i]))
                    if (visted[tmp.first + dx[i]][tmp.second + dy[i]] != 'V' && (visted[tmp.first + dx[i]][tmp.second + dy[i]] == '.' || visted[tmp.first + dx[i]][tmp.second + dy[i]] == 'P')) {
                        
                        sd[tmp.first + dx[i]][tmp.second + dy[i]] = sd[tmp.first][tmp.second] + 1;

                        if (tmp.first + dx[i] == px && tmp.second + dy[i] == py) {
                            return sd[tmp.first + dx[i]][tmp.second + dy[i]];
                        }
                        
                        visted[tmp.first + dx[i]][tmp.second + dy[i]] = 'V';
                        q.push(make_pair(tmp.first + dx[i], tmp.second + dy[i]));
                        

                    }
            }
            
        }
        return -1;
    }
    
public:
    int minTime(vector <string> park) {
        init(park);
        
        if (parkingSlot.size() < cars.size()) {
            return -1;
        }
        
        sort(parkingSlot.begin(), parkingSlot.end());
        int min = -1;
        do {
            int max = -1, tmp, diff = (int)(parkingSlot.size() - cars.size());
            
            for (int i=0; i<=diff; i++) {
                max = -1;
                
                for (int j=0; j<cars.size(); j++) {
                    tmp = getDistance(cars[j].first, cars[j].second, parkingSlot[j+i].first, parkingSlot[j+i].second);
                    if (tmp != -1 && tmp > max) {
                        max = tmp;
                    }
                }
            }
            
            if (max != -1 && (max < min || min == -1)) {
                min = max;
            }
            
        } while (next_permutation(parkingSlot.begin(), parkingSlot.end()));
        
        return min;
    }
};

int main(int argc, const char * argv[]) {
    
    Parking park;
    
    cout << park.minTime({"C.....P",
        "C.....P",
        "C.....P"}) << endl;
    
    cout << park.minTime({"C.X.....",
        "..X..X..",
        "..X..X..",
        ".....X.P"}) << endl;
    
    cout << park.minTime( {"XXXXXXXXXXX",
        "X......XPPX",
        "XC...P.XPPX",
        "X......X..X",
        "X....C....X",
        "XXXXXXXXXXX"}) << endl;
    
    cout << park.minTime({".C.",
        "...",
        "C.C",
        "X.X",
        "PPP"}) << endl;
    
    cout << park.minTime({"CCCCC",
        ".....",
        "PXPXP"}) << endl;
    
    cout << park.minTime({"..X..",
        "C.X.P",
        "..X.."}) << endl;
    
    return 0;
}
