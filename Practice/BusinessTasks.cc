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

int main(int argc, const char * argv[]) {
    BusinessTasks bt;

    cout << bt.getTasks({"a", "b", "c", "d"}, 2) << endl;
    cout << bt.getTasks({"a", "b", "c", "d", "e"}, 3) << endl;
    cout << bt.getTasks({"alpha","beta","gamma","delta","epsilon"}, 1) << endl;
    cout << bt.getTasks({"a","b"}, 1000) << endl;
    cout << bt.getTasks({"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"}, 17) << endl;
    cout << bt.getTasks({"zlqamum","yjsrpybmq","tjllfea","fxjqzznvg","nvhekxr","am","skmazcey","piklp","olcqvhg","dnpo","bhcfc","y","h","fj","bjeoaxglt","oafduixsz","kmtbaxu","qgcxjbfx","my","mlhy","bt","bo","q"}, 9000000) << endl;

    return 0;
}

