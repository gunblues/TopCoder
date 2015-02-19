class BridgeCrossing {
private:
    int time, min_time;
    int size;
    vector<bool> onOtherSide;
    vector<int> times;
    int onOtherSideCnt;
    
    void sendAnotherTwo() {
        for (int i=0; i<size; ++i)
            for (int j=0; j<size; ++j)
                if (i!=j && !onOtherSide[i] && !onOtherSide[j]) {
                    int dt = max(times[i], times[j]);
                    if (time + dt >= min_time)
                        continue;
                    
                    time += dt;
                    onOtherSide[i] = onOtherSide[j] = true;
                    onOtherSideCnt += 2;
                    
                    if (onOtherSideCnt == size) {
                        min_time = min(min_time, time);
                    }
                    else {
                        sendOneBack();
                    }
                    
                    time -= dt;
                    onOtherSide[i] = onOtherSide[j] = false;
                    onOtherSideCnt -= 2;
                    
                }
    }
    
    void sendOneBack() {
        for (int i=0; i<size; ++i) {
            if (onOtherSide[i]) {
                time += times[i];
                onOtherSide[i] = false;
                onOtherSideCnt--;
                
                sendAnotherTwo();
                
                time -= times[i];
                onOtherSide[i] = true;
                onOtherSideCnt++;
            }
            
        }
    }
    
public:
    int minTime(vector<int> times) {
        this->times = times;
        size = times.size();
        time = 0;
        min_time = 1000000000;
        onOtherSide.clear();
        onOtherSide.resize(size);
        onOtherSideCnt = 0;
        
        if (size == 1) return times[0];
        
        sendAnotherTwo();
        return min_time;
    }
};

/*
BridgeCrossing bc;

const int args[] = {10, 2, 5, 1};
vector<int> times(args, args + sizeof(args)/sizeof(args[0]));
cout << bc.minTime(times) << endl;


const int args[] = {1, 2, 3, 4, 5};
vector<int> times(args, args + sizeof(args)/sizeof(args[0]));
cout << bc.minTime(times) << endl;

const int args[] = {100};
vector<int> times(args, args + sizeof(args)/sizeof(args[0]));
cout << bc.minTime(times) << endl;


const int args[] = {1, 2, 3, 50, 99, 100};
vector<int> times(args, args + sizeof(args)/sizeof(args[0]));
cout << bc.minTime(times) << endl;
*/

