//0210 순위 검색 by CJHofficial

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size(), 0);
    map<string, vector<int>> infoMap; 
    for(int i = 0; i < info.size(); i++){
        string token;
        stringstream ss(info[i]);
        vector<vector<string>> str(4, vector<string>(2, "-"));
        int index = 0, score = 0;
        while(ss >> token){
            if(index < 4){
                str[index++][0] = token;    
            }
            else{
                score = stoi(token);
            }
        }
        
        for(int i = 0; i < 2; i++){
            string t1, t2, t3, t4;
            t1 = str[0][i];
            for(int j = 0; j < 2; j++){
                t2 = str[1][j];
                for(int k = 0; k < 2; k++){
                    t3 = str[2][k];
                    for(int l = 0; l < 2; l++){
                        t4 = str[3][l];
                        infoMap[t1 + t2 + t3 + t4].push_back(score);
                    }
                }
            }
        }
    }
    
    for(auto it = infoMap.begin(); it != infoMap.end(); it++){
        sort(it->second.begin(), it->second.end());
    }
    for(int i = 0; i < query.size(); i++){
        string str = ""; string token;
        stringstream ss(query[i]);
        int index = 0, score = 0;
        while(ss >> token){
            if(token == "and"){
                continue;
            }
            if(index++ < 4){
                str += token;
            }
            else{
                score = stoi(token);
            }
        }
        
        auto itr = lower_bound(infoMap[str].begin(), infoMap[str].end(), score);
        
        answer[i] = infoMap[str].size() - (itr - infoMap[str].begin());
    }
    
    return answer;
}