#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, t, p, curDays, curVal, ret=0;

    cin >> n;

    vector<pair<int, int>> payments(n);
    vector<int> maxVal(n+1);

    for(int i=0; i<n; i++){
        cin >> t >> p;
        payments[i] = make_pair(t, p);
    }

    for(int i=0; i<n; i++){
        ret = max(ret, maxVal[i]);
        auto lecture = payments[i];

        curDays = lecture.first;
        curVal = lecture.second;

        int newDay = i + curDays;
        if(newDay >= n+1) continue;

        maxVal[newDay] = max(maxVal[newDay], ret + curVal);
    }

    ret = max(ret, maxVal[n]);

    cout << ret << '\n';

    return 0;
}