#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> map;

bool isRemove(int y, int m, int d, string privacy) {
    int prev_y, prev_m, prev_d;
    prev_y = stoi(privacy.substr(0, 4));
    prev_m = stoi(privacy.substr(5, 2));
    prev_d = stoi(privacy.substr(8, 2));
    string type = privacy.substr(11);
    // 월에 기한 더함.
    prev_m += map[type];
    // 12월을 넘어갈 시,
    while (prev_m > 12) {
        prev_m -= 12;
        prev_y += 1;
    }
    // 현재가 기한날짜보다 작으면
    cout << y << " " << m << " " << d << "\n";
    cout << prev_y << " " << prev_m << " " << prev_d << "\n";
    cout << "==============\n";
    if (prev_y < y) return true;
    if (prev_y == y && prev_m < m) return true;
    else if (prev_y == y && prev_m == m && prev_d <= d) return true;
    return false;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    int y, m, d;
    y = stoi(today.substr(0, 4));
    m = stoi(today.substr(5, 2));
    d = stoi(today.substr(8, 2));

    for (auto i : terms) {
        map.insert({i.substr(0,1), stoi(i.substr(2))});
    }

    vector<int> answer;
    for (int i = 0; i < privacies.size(); i++) {
        if (isRemove(y, m, d, privacies[i]))           answer.push_back(i+1);
    }

    return answer;
}