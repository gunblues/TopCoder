//http://www.csie.ntnu.edu.tw/~u91029/DynamicProgramming.html
//http://zh.wikipedia.org/wiki/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92
/*
 
 Problem Statement
     
 A sequence of numbers is called a zig-zag sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a zig-zag sequence.
 For example, 1,7,4,9,2,5 is a zig-zag sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, 1,4,7,2,5 and 1,7,4,5,5 are not zig-zag sequences, the first because its first two differences are positive and the second because its last difference is zero.
 Given a sequence of integers, sequence, return the length of the longest subsequence of sequence that is a zig-zag sequence. A subsequence is obtained by deleting some number of elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
 Definition
     
 Class:
 ZigZag
 Method:
 longestZigZag
 Parameters:
 int[]
 Returns:
 int
 Method signature:
 int longestZigZag(int[] sequence)
 (be sure your method is public)
 Limits
     
 Time limit (s):
 2.000
 Memory limit (MB):
 64
 Constraints
 -
 sequence contains between 1 and 50 elements, inclusive.
 -
 Each element of sequence is between 1 and 1000, inclusive.
 Examples
 0)
 
     
 { 1, 7, 4, 9, 2, 5 }
 Returns: 6
 The entire sequence is a zig-zag sequence.
 1)
 
     
 { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 }
 Returns: 7
 There are several subsequences that achieve this length. One is 1,17,10,13,10,16,8.
 2)
 
     
 { 44 }
 Returns: 1
 
 3)
 
     
 { 1, 2, 3, 4, 5, 6, 7, 8, 9 }
 Returns: 2
 
 4)
 
     
 { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 }
 Returns: 8
 
 5)
 
     
 { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955,
 600, 947, 978, 46, 100, 953, 670, 862, 568, 188,
 67, 669, 810, 704, 52, 861, 49, 640, 370, 908,
 477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
 249, 22, 176, 279, 23, 22, 617, 462, 459, 244 }
 Returns: 36
 
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
/*
class ZigZag {
public:
    int longestZigZag(vector <int> sequence) {
        vector<int> zigzag_seq;
        
        if (sequence.size() == 1) {
            return 1;
        }
        else {
            bool first = true;
            bool positiveOrNagtive = true;
            bool find = false;
            int cur = 0;
            
            zigzag_seq.push_back(sequence[cur]);
            
            while (cur < sequence.size() - 1) {
                if ((first || positiveOrNagtive) && sequence[cur+1] > sequence[cur]) {
                    zigzag_seq.push_back(sequence[cur+1]);
                    first = false;
                    find = true;
                }
                else if ((first || !positiveOrNagtive) && sequence[cur+1] < sequence[cur]) {
                    zigzag_seq.push_back(sequence[cur+1]);
                    
                    if (first) {
                        positiveOrNagtive = false;
                    }
                    
                    first = false;
                    find = true;
                }
                else {
                    find = false;
                }
                
                if (find) {
                    positiveOrNagtive = !positiveOrNagtive;
                }
                
                ++cur;
            }
            return (int)zigzag_seq.size();
        }
    }
};
*/

class ZigZag {
public:
    int longestZigZag (vector<int> sequence) {
        vector<pair<int, int>> states;
        //first = +, second = -
        pair<int, int> temp;
        int i, j, ans=0;
        temp.first = temp.second = 1;
        for (i=0; i<sequence.size(); i++) {
            states.push_back(temp);
        }
        for (i=1; i<sequence.size(); i++) {
            for (j=0; j<i; j++) {
                if (sequence[i] - sequence[j] > 0 && states[j].second+1 > states[i].first)
                    states[i].first = states[j].second + 1;
                else if (sequence[i] - sequence[j] < 0 && states[j].first+1 > states[i].second)
                    states[i].second = states[j].first + 1;
            }
        }
        for (i=0; i<states.size(); i++) {
            ans = max(ans, states[i].first);
            ans = max(ans, states[i].second);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    ZigZag zz;
    cout << zz.longestZigZag({ 1, 7, 4, 9, 2, 5 }) << endl;
    cout << zz.longestZigZag({ 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 }) << endl;
    cout << zz.longestZigZag({ 44 }) << endl;
    cout << zz.longestZigZag({ 1, 2, 3, 4, 5, 6, 7, 8, 9 }) << endl;
    cout << zz.longestZigZag({ 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 }) << endl;
    
    cout << zz.longestZigZag({ 374, 40, 854, 203, 203, 156, 362, 279, 812, 955,
        600, 947, 978, 46, 100, 953, 670, 862, 568, 188,
        67, 669, 810, 704, 52, 861, 49, 640, 370, 908,
        477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
        249, 22, 176, 279, 23, 22, 617, 462, 459, 244 }) << endl;
    
    return 0;
}
