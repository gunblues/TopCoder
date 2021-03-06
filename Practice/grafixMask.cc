/*

Problem Statement
    
Note: This problem statement includes images that may not appear if you are using a plugin. For best results, use the Arena editor.
In one mode of the grafix software package, the user blocks off portions of a masking layer using opaque rectangles. The bitmap used as the masking layer is 400 pixels tall and 600 pixels wide. Once the rectangles have been blocked off, the user can perform painting actions through the remaining areas of the masking layer, known as holes. To be precise, each hole is a maximal collection of contiguous pixels that are not covered by any of the opaque rectangles. Two pixels are contiguous if they share an edge, and contiguity is transitive.
You are given a String[] named rectangles, the elements of which specify the rectangles that have been blocked off in the masking layer. Each String in rectangles consists of four integers separated by single spaces, with no additional spaces in the string. The first two integers are the window coordinates of the top left pixel in the given rectangle, and the last two integers are the window coordinates of its bottom right pixel. The window coordinates of a pixel are a pair of integers specifying the row number and column number of the pixel, in that order. Rows are numbered from top to bottom, starting with 0 and ending with 399. Columns are numbered from left to right, starting with 0 and ending with 599. Every pixel within and along the border of the rectangle defined by these opposing corners is blocked off.
Return a int[] containing the area, in pixels, of every hole in the resulting masking area, sorted from smallest area to greatest.
Definition
    
Class:
grafixMask
Method:
sortedAreas
Parameters:
String[]
Returns:
int[]
Method signature:
int[] sortedAreas(String[] rectangles)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Notes
-
Window coordinates are not the same as Cartesian coordinates. Follow the definition given in the second paragraph of the problem statement.
Constraints
-
rectangles contains between 1 and 50 elements, inclusive
-
each element of rectangles has the form "ROW COL ROW COL", where: "ROW" is a placeholder for a non-zero-padded integer between 0 and 399, inclusive; "COL" is a placeholder for a non-zero-padded integer between 0 and 599, inclusive; the first row number is no greater than the second row number; the first column number is no greater than the second column number
Examples
0)

    
{"0 292 399 307"}
Returns: { 116800,  116800 }
The masking layer is depicted below in a 1:4 scale diagram.

 

1)

    
{"48 192 351 207", "48 392 351 407", "120 52 135 547", "260 52 275 547"}
Returns: { 22816,  192608 }
 

2)

    
{"0 192 399 207", "0 392 399 407", "120 0 135 599", "260 0 275 599"}
Returns: { 22080,  22816,  22816,  23040,  23040,  23808,  23808,  23808,  23808 }
 

3)

    
{"50 300 199 300", "201 300 350 300", "200 50 200 299", "200 301 200 550"}
Returns: { 1,  239199 }

4)

    
{"0 20 399 20", "0 44 399 44", "0 68 399 68", "0 92 399 92",
 "0 116 399 116", "0 140 399 140", "0 164 399 164", "0 188 399 188",
 "0 212 399 212", "0 236 399 236", "0 260 399 260", "0 284 399 284",
 "0 308 399 308", "0 332 399 332", "0 356 399 356", "0 380 399 380",
 "0 404 399 404", "0 428 399 428", "0 452 399 452", "0 476 399 476",
 "0 500 399 500", "0 524 399 524", "0 548 399 548", "0 572 399 572",
 "0 596 399 596", "5 0 5 599", "21 0 21 599", "37 0 37 599",
 "53 0 53 599", "69 0 69 599", "85 0 85 599", "101 0 101 599",
 "117 0 117 599", "133 0 133 599", "149 0 149 599", "165 0 165 599",
 "181 0 181 599", "197 0 197 599", "213 0 213 599", "229 0 229 599",
 "245 0 245 599", "261 0 261 599", "277 0 277 599", "293 0 293 599",
 "309 0 309 599", "325 0 325 599", "341 0 341 599", "357 0 357 599",
 "373 0 373 599", "389 0 389 599"}
Returns: 
{ 15,  30,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,
  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  100,  115,
  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,
  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  200,
  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,
  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,
  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,
  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,
  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345 }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include <iostream>

#define f first
#define s second

using namespace std;

#define BOUND_X 400
#define BOUND_Y 600

class grafixMask {
private:
    vector<int> dx;
    vector<int> dy;
    bool matrix[BOUND_X][BOUND_Y];
    int total_area = 0;
    
    void just_do_it(vector<string> r) {
        memset(matrix, 0, sizeof(matrix));

        while(!r.empty()) {
            istringstream z(r.back());
            int a, b, c ,d;
            z >> a >> b >> c >> d;
            
            for (int i=a; i<=c; i++)
                for (int j=b; j<=d; j++)
                    matrix[i][j] = true;
            
            r.pop_back();
        }
    }

    bool in_bound(int x, int y) {
        if (x >=0 && x < BOUND_X && y >=0 && y < BOUND_Y) {
            return true;
        }
        
        return false;
    }
    
    int flood_fill(int x, int y) {
        int ret = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        
        matrix[x][y] = true;
        
        while (!q.empty()) {
            pair<int, int> tmp = q.front();
            q.pop();
            ret++;
            
            for (int i=0; i<4; i++) {
                if (in_bound(tmp.f + dx[i], tmp.s + dy[i]))
                    if (!matrix[tmp.f + dx[i]][tmp.s + dy[i]]) {
                        matrix[tmp.f + dx[i]][tmp.s + dy[i]] = true;
                        q.push(make_pair(tmp.f + dx[i], tmp.s + dy[i]));
                    }
            }
            
        }
        return ret;
    }
     
    /*
    // using recursive but it's unavailable when dimension is large
    int flood_fill(int x, int y) {
        if (!in_bound(x, y)) return total_area;
        
        if (matrix[x][y]) {
            return total_area;
        }
        
        matrix[x][y] = true;
        total_area++;
        
        for (int i=0; i<4; i++) {
            flood_fill(x + dx[i], y + dy[i]);
        }
        
        return total_area;
    }
    */
    
public:
    grafixMask() {
        dx = {0, 0, 1, -1};
        dy = {1, -1, 0, 0};
    }
    
    vector<int> sortedAreas(vector<string> rectangles) {
        vector<int> v;
        
        just_do_it(rectangles);
        
        for(int i=0; i<BOUND_X; i++)
            for(int j=0; j<BOUND_Y; j++)
                if (!matrix[i][j]) {
                    v.push_back(flood_fill(i, j));
                    total_area = 0;
                }
        
        sort(v.begin(), v.end());
        return v;
    }
};

int main(int argc, const char * argv[]) {
    grafixMask gm;

    vector<int> areas = gm.sortedAreas({"0 292 399 307"});
    for (vector<int>::iterator it=areas.begin(); it != areas.end(); ++it) {
        cout << *it << endl;
    }

    vector<int> areas2 = gm.sortedAreas({"48 192 351 207", "48 392 351 407", "120 52 135 547", "260 52 275 547"});
    for (vector<int>::iterator it=areas2.begin(); it != areas2.end(); ++it) {
        cout << *it << endl;
    }

    vector<int> areas3 = gm.sortedAreas({"0 192 399 207", "0 392 399 407", "120 0 135 599", "260 0 275 599"});
    for (vector<int>::iterator it=areas3.begin(); it != areas3.end(); ++it) {
        cout << *it << endl;
    }

    vector<int> areas4 = gm.sortedAreas({"50 300 199 300", "201 300 350 300", "200 50 200 299", "200 301 200 550"});
    for (vector<int>::iterator it=areas4.begin(); it != areas4.end(); ++it) {
        cout << *it << endl;
    }

    vector<int> areas5 = gm.sortedAreas({"0 20 399 20", "0 44 399 44", "0 68 399 68", "0 92 399 92",
            "0 116 399 116", "0 140 399 140", "0 164 399 164", "0 188 399 188",
            "0 212 399 212", "0 236 399 236", "0 260 399 260", "0 284 399 284",
            "0 308 399 308", "0 332 399 332", "0 356 399 356", "0 380 399 380",
            "0 404 399 404", "0 428 399 428", "0 452 399 452", "0 476 399 476",
            "0 500 399 500", "0 524 399 524", "0 548 399 548", "0 572 399 572",
            "0 596 399 596", "5 0 5 599", "21 0 21 599", "37 0 37 599",
            "53 0 53 599", "69 0 69 599", "85 0 85 599", "101 0 101 599",
            "117 0 117 599", "133 0 133 599", "149 0 149 599", "165 0 165 599",
            "181 0 181 599", "197 0 197 599", "213 0 213 599", "229 0 229 599",
            "245 0 245 599", "261 0 261 599", "277 0 277 599", "293 0 293 599",
            "309 0 309 599", "325 0 325 599", "341 0 341 599", "357 0 357 599",
            "373 0 373 599", "389 0 389 599"});
    for (vector<int>::iterator it=areas5.begin(); it != areas5.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}

