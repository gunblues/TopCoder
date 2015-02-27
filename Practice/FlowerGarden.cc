//
//  FlowerGarden.h
//  TopCoder
//
//  Created by hsiao kevin on 2015/2/27.
//  Copyright (c) 2015年 hsiao kevin. All rights reserved.
//
/*
 
 Problem Statement
     
 You are planting a flower garden with bulbs to give you joyous flowers throughout the year. However, you wish to plant the flowers such that they do not block other flowers while they are visible.
 You will be given a vector <int> height, a vector <int> bloom, and a vector <int> wilt. Each type of flower is represented by the element at the same index of height, bloom, and wilt. height represents how high each type of flower grows, bloom represents the morning that each type of flower springs from the ground, and wilt represents the evening that each type of flower shrivels up and dies. Each element in bloom and wilt will be a number between 1 and 365 inclusive, and wilt[i] will always be greater than bloom[i]. You must plant all of the flowers of the same type in a single row for appearance, and you also want to have the flowers in rows which are more towards the front be as tall as possible. However, if a flower type is taller than another type, and both types can be out of the ground at the same time, the shorter flower must be planted in front of the taller flower to prevent blocking. A flower blooms in the morning, and wilts in the evening, so even if one flower is blooming on the same day another flower is wilting, one can block the other.
 For example, if your garden of flowers has heights 1, 2, and 3, and the flowers of height 3 bloom and wilt with flowers of height 1, but neither conflicts with 2, your best arrangement would be 2,1,3. 1,3,2 would be possible, but then the first row of flowers is shorter, which is less desirable.
 You should return a vector <int> which contains the elements of height in the order you should plant your flowers to acheive the above goals. The front of the garden is represented by the first element in your return value, and is where you view the garden from. The elements of height will all be unique, so there will always be a well-defined ordering.
 Definition
     
 Class:
 FlowerGarden
 Method:
 getOrdering
 Parameters:
 vector <int>, vector <int>, vector <int>
 Returns:
 vector <int>
 Method signature:
 vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt)
 (be sure your method is public)
 Limits
     
 Time limit (s):
 2.000
 Memory limit (MB):
 64
 Constraints
 -
 height will have between 2 and 50 elements, inclusive.
 -
 bloom will have the same number of elements as height
 -
 wilt will have the same number of elements as height
 -
 height will have no repeated elements.
 -
 Each element of height will be between 1 and 1000, inclusive.
 -
 Each element of bloom will be between 1 and 365, inclusive.
 -
 Each element of wilt will be between 1 and 365, inclusive.
 -
 For each element i of bloom and wilt, wilt[i] will be greater than bloom[i].
 Examples
 0)
 
     
 {5,4,3,2,1}
 {1,1,1,1,1}
 {365,365,365,365,365}
 Returns: { 1,  2,  3,  4,  5 }
 These flowers all bloom on January 1st and wilt on December 31st. Since they all may block each other, you must order them from shortest to tallest.
 1)
 
     
 {5,4,3,2,1}
 {1,5,10,15,20}
 {4,9,14,19,24}
 Returns: { 5,  4,  3,  2,  1 }
 The same set of flowers now bloom all at separate times. Since they will never block each other, you can order them from tallest to shortest to get the tallest ones as far forward as possible.
 2)
 
     
 {5,4,3,2,1}
 {1,5,10,15,20}
 {5,10,15,20,25}
 Returns: { 1,  2,  3,  4,  5 }
 Although each flower only blocks at most one other, they all must be ordered from shortest to tallest to prevent any blocking from occurring.
 3)
 
     
 {5,4,3,2,1}
 {1,5,10,15,20}
 {5,10,14,20,25}
 Returns: { 3,  4,  5,  1,  2 }
 The difference here is that the third type of flower wilts one day earlier than the blooming of the fourth flower. Therefore, we can put the flowers of height 3 first, then the flowers of height 4, then height 5, and finally the flowers of height 1 and 2. Note that we could have also ordered them with height 1 first, but this does not result in the maximum possible height being first in the garden.
 4)
 
     
 {1,2,3,4,5,6}
 {1,3,1,3,1,3}
 {2,4,2,4,2,4}
 Returns: { 2,  4,  6,  1,  3,  5 }
 
 5)
 
     
 {3,2,5,4}
 {1,2,11,10}
 {4,3,12,13}
 Returns: { 4,  5,  2,  3 }
 
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

class FlowerGarden {
public:
    vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt) {
        for (int i=0; i<height.size(); i++) {
            for (int j=i+1; j<height.size(); j++) {
                if (
                    (height[i] > height[j] && ((bloom[i] >= bloom[j] && bloom[i] <= wilt[j]) || (bloom[j] >= bloom[i] && bloom[j] <= wilt[i])))
                    ||
                   (height[i] < height[j] && ((bloom[i] < bloom[j] && wilt[i] < bloom[j]) || (bloom[i] > wilt[j] && wilt[i] < bloom[j])))
                     ) {
                    swap(height[i], height[j]);
                    swap(bloom[i], bloom[j]);
                    swap(wilt[i], wilt[j]);
                }
            }
        }

        for (int i=0; i<(int)height.size(); ++i) {
            cout << height[i] << " ";
        }
        cout << endl;

        return height;
    }
};

int main(int argc, const char * argv[]) {
    FlowerGarden fg;
    fg.getOrdering({5,4,3,2,1}, {1,1,1,1,1}, {365,365,365,365,365});
    fg.getOrdering({5,4,3,2,1}, {1,5,10,15,20}, {4,9,14,19,24});
    fg.getOrdering({5,4,3,2,1}, {1,5,10,15,20}, {5,10,15,20,25});
    fg.getOrdering({5,4,3,2,1}, {1,5,10,15,20}, {5,10,14,20,25});
    fg.getOrdering({1,2,3,4,5,6}, {1,3,1,3,1,3}, {2,4,2,4,2,4});
    fg.getOrdering({3,2,5,4}, {1,2,11,10}, {4,3,12,13});
    
    return 0;
}


