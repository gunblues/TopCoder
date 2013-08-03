#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class MNS {

    public:

        int combos(vector<int> numbers) {

            for(int i=0; i<numbers.size(); i++) {
                if(numbers[i] < 0 || numbers[i] > 9) {
                    return 0;
                }
            }
    
            sort(numbers.begin(), numbers.end());

            int count = 0;
            do {
                if( 
                        numbers[0] + numbers[1] + numbers[2] == numbers[3] + numbers[4] + numbers[5] &&
                        numbers[3] + numbers[4] + numbers[5] == numbers[6] + numbers[7] + numbers[8] &&
                        numbers[6] + numbers[7] + numbers[8] == numbers[0] + numbers[3] + numbers[6] &&
                        numbers[0] + numbers[3] + numbers[6] == numbers[1] + numbers[4] + numbers[7] &&
                        numbers[1] + numbers[4] + numbers[7] == numbers[2] + numbers[5] + numbers[8]
                  ) { 
                    count++;
                }   

            } while (next_permutation(numbers.begin(), numbers.end()));

            return count;
        }

};

int main() {
    MNS mns;

    int numbers[] = {1, 2, 3, 3, 2, 1, 2, 2, 2}; 
    vector<int> v(numbers, numbers + sizeof(numbers)/sizeof(int));
    cout << mns.combos(v) << endl;

    int numbers2[] = {4, 4, 4, 4, 4, 4, 4, 4, 4}; 
    vector<int> v2(numbers2, numbers2 + sizeof(numbers2)/sizeof(int));
    cout << mns.combos(v2) << endl;

    int numbers3[] = {1, 5, 1, 2, 5, 6, 2, 3, 2}; 
    vector<int> v3(numbers3, numbers3 + sizeof(numbers3)/sizeof(int));
    cout << mns.combos(v3) << endl;

    int numbers4[] = {1, 2, 6, 6, 6, 4, 2, 6, 4}; 
    vector<int> v4(numbers4, numbers4 + sizeof(numbers4)/sizeof(int));
    cout << mns.combos(v4) << endl;


    return 0;
}
