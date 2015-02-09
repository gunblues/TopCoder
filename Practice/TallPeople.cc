#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <algorithm>

using namespace std;

#define DEBUG
class TallPeople {
    public:
        int h[55][55];
        vector <int> getPeople(vector <string> people) {
            int n = people.size(), m;
            for (int i=0; i<n; i++) {
                istringstream stream(people[i]);
                int ct = 0;
                for(; stream >> h[i][ct++]; );
                m = ct-1;
            }
            #ifndef DEBUG
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) printf("%d ", h[i][j]);
                printf("\n");
            }
            #endif
            vector <int> ans(2);
            ans[0] = -1, ans[1] = 1050;
            for (int i=0; i<n; i++) {
                int x = h[i][0];
                for (int j=0; j<m; j++) x = min(x, h[i][j]);
                ans[0] = max(ans[0], x);
            }
            for (int i=0; i<m; i++) {
                int x = h[0][i];
                for (int j=0; j<n; j++) x = max(x, h[j][i]);
                ans[1] = min(ans[1], x);
            }
            printf("%d, %d\n", ans[0], ans[1]);
            return ans;
    }
};

int main() {
    TallPeople tp;

    const char* args[] = {"9 2 3", "4 8 7"};
    vector<string> v(args, args + sizeof(args)/sizeof(args[0])); //get array size

    const char* args2[] = {"1 2", "4 5", "3 6"};
    vector<string> v2(args2, args2 + sizeof(args2)/sizeof(args2[0])); //get array size

    const char* args3[] = {"1 1", "1 1"};
    vector<string> v3(args3, args3 + sizeof(args3)/sizeof(args3[0])); //get array size

    tp.getPeople(v);
    tp.getPeople(v2);
    tp.getPeople(v3);

    return 0;
}
