//22.01.22 �Ű� ��� �ޱ� by CJHofficial

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map <string, vector<string>> MAP; //�Ű� �� ����, �� ������ �Ű��� �������� ����
    unordered_map <string, vector<string>> BAN; //�Ű� ���� ����, �� ������ �Ű��� �������� ����
    unordered_map <string, int> COUNT;
    for (string s : report) {
        //���� �������� �и�
        string arr[2];
        istringstream stt(s);
        stt >> arr[0] >> arr[1];
        //�ִ��� Ȯ��
        auto it = find(MAP[arr[0]].begin(), MAP[arr[0]].end(), arr[1]);
        if (it == MAP[arr[0]].end()) {
            MAP[arr[0]].push_back(arr[1]); //�Ű����� ������ �߰�
        }
        //�ִ��� Ȯ��
        auto it2 = find(BAN[arr[1]].begin(), BAN[arr[1]].end(), arr[0]);
        if (it2 == BAN[arr[1]].end()) {
            BAN[arr[1]].push_back(arr[0]); //�Ű����� ������ �߰�
        }
    }
    for (string s : id_list) {
        if (BAN[s].size() >= k) {
            for (string user : BAN[s]) {
                COUNT[user]++;
            }
        }
    }
    for (string s : id_list) {
        answer.push_back(COUNT[s]);
    }
    return answer;
}