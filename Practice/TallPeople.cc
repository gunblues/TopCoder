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

/*
TallPeople tp;

 const char* args[] = {"9 2 3", "4 8 7"};
 vector<string> people(args, args + sizeof(args)/sizeof(args[0]));
 
 vector<int> ret = tp.getPeople(people);
 for(vector<int>::iterator it = ret.begin(); it != ret.end(); ++it) {
 cout << *it << endl;
 }
 
 const char* args[] = {"1 2", "4 5", "3 6"};
 vector<string> people(args, args + sizeof(args)/sizeof(args[0]));
 
 vector<int> ret = tp.getPeople(people);
 for(vector<int>::iterator it = ret.begin(); it != ret.end(); ++it) {
 cout << *it << endl;
 }
 
 
 const char* args[] = {"1 1", "1 1"};
 vector<string> people(args, args + sizeof(args)/sizeof(args[0]));
 
 vector<int> ret = tp.getPeople(people);
 for(vector<int>::iterator it = ret.begin(); it != ret.end(); ++it) {
 cout << *it << endl;
 }
 */
