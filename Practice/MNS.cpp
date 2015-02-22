/*

Problem Statement
    
9 numbers need to be arranged in a magic number square. A magic number square is a square of numbers that is arranged such that every row and column has the same sum. For example:
1 2 3
3 2 1
2 2 2
Create a class MNS containing a method combos which takes as an argument a vector <int> numbers and returns the number of distinct ways those numbers can be arranged in a magic number square. Two magic number squares are distinct if they differ in value at one or more positions. For example, there is only one magic number square that can be made of 9 instances of the same number.
Definition
    
Class:
MNS
Method:
combos
Parameters:
vector <int>
Returns:
int
Method signature:
int combos(vector <int> numbers)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Notes
-
Unlike some versions of the magic number square, the numbers do not have to be unique.
Constraints
-
numbers will contain exactly 9 elements.
-
each element of numbers will be between 0 and 9, inclusive.
Examples
0)

    
{1,2,3,3,2,1,2,2,2}
Returns: 18

1)

    
{4,4,4,4,4,4,4,4,4}
Returns: 1

2)

    
{1,5,1,2,5,6,2,3,2}
Returns: 36

3)

    
{1,2,6,6,6,4,2,6,4}
Returns: 0

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

class MNS {
public:
    int combos(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());
        
        int ret = 0;
        do {
            if (
                (numbers[0]+numbers[1]+numbers[2] == numbers[3]+numbers[4]+numbers[5]) &&
                (numbers[3]+numbers[4]+numbers[5] == numbers[6]+numbers[7]+numbers[8]) &&
                (numbers[0]+numbers[3]+numbers[6] == numbers[1]+numbers[4]+numbers[7]) &&
                (numbers[1]+numbers[4]+numbers[7] == numbers[2]+numbers[5]+numbers[8]) &&
                (numbers[2]+numbers[5]+numbers[8] == numbers[0]+numbers[1]+numbers[2])
                ) {
                    ++ret;
            }
        } while (next_permutation(numbers.begin(), numbers.end()));
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    MNS mns;
    cout << mns.combos({1,2,3,3,2,1,2,2,2}) << endl;
    cout << mns.combos({4,4,4,4,4,4,4,4,4}) << endl;
    cout << mns.combos({1,5,1,2,5,6,2,3,2}) << endl;
    cout << mns.combos({1,2,6,6,6,4,2,6,4}) << endl;
    return 0;
}

