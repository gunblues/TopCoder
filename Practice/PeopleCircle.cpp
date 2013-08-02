#include <string.h>
#include <string>
#include <iostream>

using namespace std;

class PeopleCircle {
    public:
        string order(int numMales, int numFemales, int K) {

            int idx = 0;
            int total = numMales + numFemales;
            
            char ret[total];
            memset(ret, 'M', sizeof(ret));
            ret[total] = '\0';
            int manCount = 0;

            while(numFemales > 0) {
                int pos = idx % total;

                if(ret[pos] == 'M') {
                    manCount++;

                    if(manCount % K == 0) {
                        ret[pos] = 'F';
                        numFemales--;
                    }
                }
                idx++;
            }

            return ret;

        }
};

int main() {
    PeopleCircle pc;

    cout << pc.order(5, 3, 2) << endl;
    cout << pc.order(7, 3, 1) << endl;
    cout << pc.order(25, 25, 1000) << endl;
    cout << pc.order(5, 5, 3) << endl;
    cout << pc.order(1, 0, 245) << endl;

    return 0;
}
