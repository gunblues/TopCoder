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

class TallPeople {
    public:
        vector<int> getPeople(vector<string> people) {
            vector<int> shortTall;
            vector<int> TallShort;
            int person;
            for(std::vector<string>::size_type i = 0; i != people.size(); i++) {
                istringstream ss(people[i]);
                int j=0;
                while (ss >> person) {
                    if (shortTall.size() <= i) {
                        shortTall.push_back(person);
                    }
                    else if (person < shortTall[i]) {
                        shortTall[i] = person;
                    }

                    if (TallShort.size() <= j) {
                        TallShort.push_back(person);
                    }
                    else if (person > TallShort[j]) {
                        TallShort[j] = person;
                    }

                    j++;
                }
            }

            int sT = *max_element(shortTall.begin(), shortTall.end());
            int Ts = *min_element(TallShort.begin(), TallShort.end());

            const int arr[] = {sT, Ts};
            vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]));

            return vec;
        }
};

int main(int argc, const char * argv[]) {
    TallPeople tp;

    vector<int> ret = tp.getPeople({"9 2 3", "4 8 7"});
    for(vector<int>::iterator it = ret.begin(); it != ret.end(); ++it) {
        cout << *it << endl;
    }

    vector<int> ret = tp.getPeople({"1 2", "4 5", "3 6"});
    for(vector<int>::iterator it = ret.begin(); it != ret.end(); ++it) {
        cout << *it << endl;
    }

    vector<int> ret = tp.getPeople({"1 1", "1 1"});
    for(vector<int>::iterator it = ret.begin(); it != ret.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}

