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

class SmartWordToy {
    public:
        int minPresses(string start, string finish, vector<string> forbid) {
            queue<string> data;

            map<string, int> levels;
            map<string, int> visited;

            bool flag2 = false;

            data.push(start);
            visited[start] = 1;
            levels[start] = 0;

            for (int i=0; i<forbid.size(); i++) {
                istringstream t(forbid[i]);
                string t2; int index = 0; int flag = 0;
                while (t >> t2) {
                    if(t2.find(finish[index]) == -1) {
                        flag = 1;
                        break;
                    }
                    index++;
                }

                if (flag == 0) {
                    flag2 = true;
                    break;
                }
            }

            if (flag2) {
                return -1;
            }

            int minV = 1 << 30;
            int found = 0;
            while (data.size() != 0) {
                string item = data.front();
                data.pop();

                for (int i=0; i<item.length(); i++) {
                    for (int j=1; j<=2; j++) {
                        string temp = item;
                        if (j%2 == 0) {
                            if (temp[i] != 'z') {
                                temp[i] = temp[i] + 1;
                            }
                            else {
                                temp[i] = 'a';
                            }
                        }
                        else {
                            if (temp[i] != 'a') {
                                temp[i] = temp[i] -1;
                            }
                        }

                        cout << temp << endl;

                        if (temp == finish) {
                            found = 1;
                            minV = min(minV, levels[item] + 1);
                            return minV;
                            continue;
                        }

                        if (!visited[temp]) {
                            flag2 = false;
                            for (int i=0; i<forbid.size(); i++) {
                                istringstream t(forbid[i]);
                                string t2; int index = 0; int flag = 0;
                                while (t >> t2) {
                                    if (t2.find(temp[index]) == -1) {
                                        flag = 1;
                                        break;
                                    }

                                    index++;
                                }

                                if (flag == 0) {
                                    flag2 = true;
                                    break;
                                }
                            }
            
                            if (flag2) {
                                visited[temp] = 1;
                                cout << "NOT PUSHING" << temp << endl;
                            }
                            else {
                                visited[temp] = 1;
                                levels[temp] = levels[item] + 1;
                                data.push(temp);
                            }

                        }
                    }
                }
            }

            if (found) {
                return minV;
            }
            else {
                return -1;
            }
        }
};

int main() {
    return 0;
}
            
