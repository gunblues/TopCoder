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

int main(int argc, const char * argv[]) {
    BridgeCrossing bc;

    cout << bc.minTime({1, 2, 5, 10}) << endl;
    cout << bc.minTime({1, 2, 3, 4, 5}) << endl;
    cout << bc.minTime({100}) << endl;
    cout << bc.minTime({1, 2, 3, 50, 99, 100}) << endl;

    return 0;
}
