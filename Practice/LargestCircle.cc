/*
 
 Problem Statement
     
 NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.
 Given a regular square grid, with some number of squares marked, find the largest circle you can draw on the grid that does not pass through any of the marked squares. The circle must be centered on a grid point (the corner of a square) and the radius must be an integer. Return the radius of the circle.
 The grid will be given as a String[], with each character representing a square. A '.' represents an empty square, and a '#' represents a marked square.
 The circle may intersect the corner of a marked square, but may not pass through the interior. For example, given the grid:
 
 { "############",
 "###......###",
 "##.######.##",
 "#.########.#",
 "#.##..####.#",
 "#.##..####.#",
 "#.########.#",
 "#.########.#",
 "#.########.#",
 "##.######.##",
 "###......###",
 "############" }
 two circles can be drawn with radii 1 and 5, as shown below:
 
 
 Therefore, your method should return 5.
 Circles may not extend outside of the grid, and must have a radius of at least 1. If no such circle exists, return 0.
 Definition
     
 Class:
 LargestCircle
 Method:
 radius
 Parameters:
 String[]
 Returns:
 int
 Method signature:
 int radius(String[] grid)
 (be sure your method is public)
 Limits
     
 Time limit (s):
 2.000
 Memory limit (MB):
 64
 Constraints
 -
 grid will contain between 1 and 50 elements, inclusive.
 -
 Each element of grid will contain between 1 and 50 characters, inclusive.
 -
 Each element of grid will contain the same number of characters.
 -
 Each element of grid will contain only the characters '.' and '#'.
 Examples
 0)
 
     
 { "####",
 "#..#",
 "#..#",
 "####" }
 Returns: 1
 Only one circle fits in this grid -- a circle of radius 1, in the center of the grid.
 1)
 
     
 { "############",
 "###......###",
 "##.######.##",
 "#.########.#",
 "#.##..####.#",
 "#.##..####.#",
 "#.########.#",
 "#.########.#",
 "#.########.#",
 "##.######.##",
 "###......###",
 "############" }
 Returns: 5
 This is the example from the problem statement.
 2)
 
     
 { ".........." }
 Returns: 0
 The grid must be at least two squares wide and tall in order for any circles to fit.
 3)
 
     
 { "#######",
 "#######",
 "#######",
 "#######",
 "#######" }
 Returns: 0
 
 4)
 
     
 { "#####.......",
 "#####.......",
 "#####.......",
 "............",
 "............",
 "............",
 "............",
 "............",
 "............",
 "............" }
 Returns: 4
 A circle of radius 4 fits in this grid, as shown here:
 
 5)
 
     
 { "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
 "...#...#...#...#...#...#...#...#...#...#...#...#..",
 "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
 ".#...#...#...#...#...#...#...#...#...#...#...#...#",
 "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
 "...#...#...#...#...#...#...#...#...#...#...#...#..",
 "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
 ".#...#...#...#...#...#...#...#...#...#...#...#...#",
 "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
 "...#...#...#...#...#...#...#...#...#...#...#...#.#",
 "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#." }
 Returns: 0
 
 6)
 
     
 { ".........................#........................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 "..................................................",
 ".................................................." }
 Returns: 24
 
 This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class LargestCircle {
    int possible(vector<string> &grid, int cx, int cy, int r) {
        for (int y=-(r-1); y<r-1; y++) {
            double x = sqrt((double)r*r-y*y);
            int fx = (int)floor(x + 0.000000001);
            printf("y %d %d %d %d %d %f\n", cx, cy, r, cx, y, x);
            if (fx == x && y < 0) {
                if (grid[cx-fx][cy+y-1] == '#' ||
                    grid[cx-fx-1][cy+y] == '#' ||
                    grid[cx+fx-1][cy+y-1] == '#' ||
                    grid[cx+fx][cy+y] == '#') {
                    return 0;
                }
            } else if (fx == x && y == 0) {
                if (grid[cx-fx][cy+y-1] == '#' ||
                    grid[cx-fx][cy+y] == '#' ||
                    grid[cx+fx-1][cy+y-1] == '#'||
                    grid[cx+fx-1][cy+y] == '#') {
                    return 0;
                }
            } else if (fx == x && y > 0) {
                if (grid[cx-fx-1][cy+y-1] == '#' ||
                    grid[cx-fx][cy+y] == '#' ||
                    grid[cx+fx][cy+y-1] == '#' ||
                    grid[cx+fx-1][cy+y] == '#') {
                    return 0;
                }
            } else {
                if (grid[cx-fx-1][cy+y-1] == '#' ||
                    grid[cx-fx-1][cy+y] == '#' ||
                    grid[cx+fx][cy+y-1] == '#' ||
                    grid[cx+fx][cy+y] == '#') {
                    return 0;
                }
            }
        }
        
        for (int x=-(r-1); x<r-1; x++) {
            double y = sqrt((double)r*r-x*x);
            int fy = (int)floor(y + 0.000000001);
            printf("x %d %d %d %d %d\n", cx, cy, r, cx + x, fy);
            if (fy == y && x < 0) {
                if (grid[cx+x-1][cy-fy] == '#' ||
                    grid[cx+x][cy-fy-1] == '#' ||
                    grid[cx+x-1][cy+fy-1] == '#' ||
                    grid[cx+x][cy+fy] == '#') {
                    return 0;
                }
            } else if (fy == y && x == 0) {
                if (grid[cx+x-1][cy-fy] == '#' ||
                    grid[cx+x][cy-fy] == '#' ||
                    grid[cx+x-1][cy+fy-1] == '#'||
                    grid[cx+x][cy+fy-1] == '#') {
                    return 0;
                }
            } else if (fy == y && x > 0) {
                if (grid[cx+x-1][cy-fy-1] == '#' ||
                    grid[cx+x][cy-fy] == '#' ||
                    grid[cx+x-1][cy+fy] == '#' ||
                    grid[cx+x][cy+fy-1] == '#') {
                    return 0;
                }
            } else {
                if (grid[cx+x-1][cy-fy-1] == '#' ||
                    grid[cx+x][cy-fy-1] == '#' ||
                    grid[cx+x-1][cy+fy] == '#' ||
                    grid[cx+x][cy+fy] == '#') {
                    return 0;
                }
            }
        }
        return 1;
    }
    
public:
    int radius(vector<string> grid) {
        cout << (int)grid[0].size() << endl;
        cout << (int)grid.size() << endl;
        
        for (int r = 25; r >= 1; r--) {
            for (int y = r; y <= (int)grid[0].size() - r; y++) {
                for (int x = r; x <= (int)grid.size() -r; x++) {
                    if (possible(grid, x, y, r)) {
                        return r;
                    }
                }
            }
        }
        
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    LargestCircle lc;
    
    cout << lc.radius({"####", "#..#", "#..#", "####"}) << endl;
    cout << lc.radius({"############",
        "###......###",
        "##.######.##",
        "#.########.#",
        "#.##..####.#",
        "#.##..####.#",
        "#.########.#",
        "#.########.#",
        "#.########.#",
        "##.######.##",
        "###......###",
        "############"}) << endl;
    
    return 0;
}

