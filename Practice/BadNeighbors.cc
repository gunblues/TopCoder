//
//  BadNeighbors.h
//  TopCoder
//
//  Created by hsiao kevin on 2015/2/25.
//  Copyright (c) 2015年 hsiao kevin. All rights reserved.
//
/*
 
 Problem Statement
     
 The old song declares "Go ahead and hate your neighbor", and the residents of Onetinville have taken those words to heart. Every resident hates his next-door neighbors on both sides. Nobody is willing to live farther away from the town's well than his neighbors, so the town has been arranged in a big circle around the well. Unfortunately, the town's well is in disrepair and needs to be restored. You have been hired to collect donations for the Save Our Well fund.
 Each of the town's residents is willing to donate a certain amount, as specified in the vector <int> donations, which is listed in clockwise order around the well. However, nobody is willing to contribute to a fund to which his neighbor has also contributed. Next-door neighbors are always listed consecutively in donations, except that the first and last entries in donations are also for next-door neighbors. You must calculate and return the maximum amount of donations that can be collected.
 Definition
     
 Class:
 BadNeighbors
 Method:
 maxDonations
 Parameters:
 vector <int>
 Returns:
 int
 Method signature:
 int maxDonations(vector <int> donations)
 (be sure your method is public)
 Limits
     
 Time limit (s):
 2.000
 Memory limit (MB):
 64
 Constraints
 -
 donations contains between 2 and 40 elements, inclusive.
 -
 Each element in donations is between 1 and 1000, inclusive.
 Examples
 0)
 
     
 { 10, 3, 2, 5, 7, 8 }
 Returns: 19
 The maximum donation is 19, achieved by 10+2+7. It would be better to take 10+5+8 except that the 10 and 8 donations are from neighbors.
 1)
 
     
 { 11, 15 }
 Returns: 15
 
 2)
 
     
 { 7, 7, 7, 7, 7, 7, 7 }
 Returns: 21
 
 3)
 
     
 { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 }
 Returns: 16
 
 4)
 
     
 { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,
 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 }
 Returns: 2926
 
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

using namespace std;

class BadNeighbors {
public:
    int maxDonations(vector <int> donations) {
        vector<int> d1;
        vector<int> d2;
        vector<int> d = donations;
        int i=0, mymax = 0;
        int n = (int)donations.size();
        
        for(i=0; i<n-1; i++) {
            d1.push_back(donations[i]);
        }
        for (i=1; i<n; i++) {
            d2.push_back(donations[i]);
        }
        
        d[0] = d1[0];
        d[1] = d1[1];
        d[2] = max(d[0], 0) + d1[2];
        mymax = max(d[0], d[1]);
        mymax = max(mymax, d[2]);
        
        //最多只有可能i-2或i-3，如果i-4代表中間又多一個人了
        for (i=3; i<d1.size(); i++) {
            d[i] = max(d[i-2], d[i-3]) + d1[i];
            mymax = mymax>d[i] ? mymax : d[i];
            cout << "i=" << i << ":" << d[i] << " ";
        }
        
        cout << endl;
        
        d[0] = d2[0];
        d[1] = d2[1];
        d[2] = max(d[0], 0) + d2[2];
        mymax = max(mymax, d[0]);
        mymax = max(mymax, d[1]);
        mymax = max(mymax, d[2]);
        
        for (i=3; i<d2.size(); i++) {
            d[i] = max(d[i-2], d[i-3]) + d2[i];
            mymax = mymax > d[i] ? mymax : d[i];
            cout << "i=" << i << ":" << d[i] << " ";
        }
        
        cout << endl;
        
        return mymax;
    }
};

int main(int argc, const char * argv[]) {
    BadNeighbors bn;
    cout << bn.maxDonations({ 10, 3, 2, 5, 7, 8 }) << endl;
    cout << bn.maxDonations({ 11, 15 }) << endl;
    
    cout << bn.maxDonations({ 7, 7, 7, 7, 7, 7, 7 }) << endl;
    cout << bn.maxDonations({ 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 }) << endl;
    
    cout << bn.maxDonations({ 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,
        6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
        52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 }) << endl;
    
    return 0;
}


