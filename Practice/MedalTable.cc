//
//  MedalTable.h
//  TopCoder
//
//  Created by hsiao kevin on 2015/2/27.
//  Copyright (c) 2015年 hsiao kevin. All rights reserved.
//
/*
 
 Problem Statement
     
 The Olympic Games in Athens end tomorrow. Given the results of the olympic disciplines, generate and return the medal table.  The results of the disciplines are given as a vector <string> results, where each element is in the format "GGG SSS BBB". GGG, SSS and BBB are the 3-letter country codes (three capital letters from 'A' to 'Z') of the countries winning the gold, silver and bronze medal, respectively.  The medal table is a vector <string> with an element for each country appearing in results. Each element has to be in the format "CCO G S B" (quotes for clarity), where G, S and B are the number of gold, silver and bronze medals won by country CCO, e.g. "AUT 1 4 1". The numbers should not have any extra leading zeros. Sort the elements by the number of gold medals won in decreasing order. If several countries are tied, sort the tied countries by the number of silver medals won in decreasing order. If some countries are still tied, sort the tied countries by the number of bronze medals won in decreasing order. If a tie still remains, sort the tied countries by their 3-letter code in ascending alphabetical order.
 Definition
     
 Class:
 MedalTable
 Method:
 generate
 Parameters:
 vector <string>
 Returns:
 vector <string>
 Method signature:
 vector <string> generate(vector <string> results)
 (be sure your method is public)
 Limits
     
 Time limit (s):
 2.000
 Memory limit (MB):
 64
 Constraints
 -
 results contains between 1 and 50 elements, inclusive.
 -
 Each element of results is formatted as described in the problem statement.
 -
 No more than 50 different countries appear in results.
 Examples
 0)
 
     
 {"ITA JPN AUS", "KOR TPE UKR", "KOR KOR GBR", "KOR CHN TPE"}
 Returns:
 { "KOR 3 1 0",
 "ITA 1 0 0",
 "TPE 0 1 1",
 "CHN 0 1 0",
 "JPN 0 1 0",
 "AUS 0 0 1",
 "GBR 0 0 1",
 "UKR 0 0 1" }
 These are the results of the archery competitions.
 1)
 
     
 {"USA AUT ROM"}
 Returns: { "USA 1 0 0",  "AUT 0 1 0",  "ROM 0 0 1" }
 
 2)
 
     
 {"GER AUT SUI", "AUT SUI GER", "SUI GER AUT"}
 Returns: { "AUT 1 1 1",  "GER 1 1 1",  "SUI 1 1 1" }
 
 This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct MedalRank {
    string country;
    vector<int> medal; //0-gold, 1-silver, 2-bronze
};

class MedalTable {
    static bool cmp(const MedalRank& a, const MedalRank& b) {
        if (a.medal[0] > b.medal[0])
            return true;
        else if (a.medal[0] == b.medal[0]) {
            if (a.medal[1] > b.medal[1]) {
                return true;
            }
            else if (a.medal[1] == b.medal[1]) {
                if (a.medal[2] > b.medal[2]) {
                    return true;
                }
                else if (a.medal[2] == b.medal[2]) {
                    return a.country < b.country;
                }
            }
        }
        
        return false;
    }
public:
    vector <string> generate(vector<string> results) {
        map<string, MedalRank> table;
        vector<MedalRank> tableV;
        
        vector<string> countrys(results.size());
        while(!results.empty()) {
            istringstream iss(results.back());
            vector<string> levels(3);
            iss >> levels[0] >> levels[1] >> levels[2];
            
            for (int i=0; i<levels.size(); i++) {
                if (table.find(levels[i]) == table.end()) {
                    table[levels[i]].country = levels[i];
                    table[levels[i]].medal.resize(3);
                    table[levels[i]].medal[i] = 1;
                }
                else {
                    table[levels[i]].medal[i] = table[levels[i]].medal[i] + 1;
                }
            }
            
            results.pop_back();
        }
        
        for (map<string, MedalRank>::iterator it=table.begin(); it != table.end(); ++it) {
            tableV.push_back(it->second);
        }
        
        sort(tableV.begin(), tableV.end(), cmp);
        
        vector<string> ret;
        for (int i=0; i<tableV.size(); i++) {
            cout << tableV[i].country + " " + to_string(tableV[i].medal[0]) + " " + to_string(tableV[i].medal[1]) + " " + to_string(tableV[i].medal[2]) << endl;
            ret.push_back(tableV[i].country + " " + to_string(tableV[i].medal[0]) + " " + to_string(tableV[i].medal[1]) + " " + to_string(tableV[i].medal[2]));
        }
        cout << endl;
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    MedalTable mt;
    mt.generate({"ITA JPN AUS", "KOR TPE UKR", "KOR KOR GBR", "KOR CHN TPE"});
    mt.generate({"USA AUT ROM"});
    mt.generate({"GER AUT SUI", "AUT SUI GER", "SUI GER AUT"});
    
    return 0;
}


