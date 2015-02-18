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

class BusinessTasks {
public:
    string getTasks(vector<string> list, int n) {
        
        int begin = 0;
        while (list.size() > 1) {
            int remove = ((begin + (n - 1)) % list.size());
            list.erase(list.begin() + remove);
            begin = remove;
        }
        
        return list[0];
    }
};

/*
 BusinessTasks bt;

 const char* args[] = {"a", "b", "c", "d"};
 vector<string> list(args, args + sizeof(args)/sizeof(args[0]));
 cout << bt.getTasks(list, 2) << endl;
 
 const char* args[] = {"a", "b", "c", "d", "e"};
 vector<string> list(args, args + sizeof(args)/sizeof(args[0]));
 cout << bt.getTasks(list, 3) << endl;
 
 const char* args[] = {"alpha","beta","gamma","delta","epsilon"};
 vector<string> list(args, args + sizeof(args)/sizeof(args[0]));
 cout << bt.getTasks(list, 1) << endl;
 
 const char* args[] = {"a","b"};
 vector<string> list(args, args + sizeof(args)/sizeof(args[0]));
 cout << bt.getTasks(list, 1000) << endl;
 
 const char* args[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t",
 "u","v","w","x","y","z"};
 vector<string> list(args, args + sizeof(args)/sizeof(args[0]));
 cout << bt.getTasks(list, 17) << endl;
 
 const char* args[] = {"zlqamum","yjsrpybmq","tjllfea","fxjqzznvg","nvhekxr","am","skmazcey","piklp",
 "olcqvhg","dnpo","bhcfc","y","h","fj","bjeoaxglt","oafduixsz","kmtbaxu",
 "qgcxjbfx","my","mlhy","bt","bo","q"};
 vector<string> list(args, args + sizeof(args)/sizeof(args[0]));
 cout << bt.getTasks(list, 9000000) << endl;
*/
