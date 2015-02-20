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

