#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int dp[100001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k, w, v;

    cin >> n >> k;
    vector<pair<int, int>> values(n);
    
    for(int i=0; i<n; i++){
        cin >> w >> v;
        values[i] = make_pair(w, v);
    }

    for(int i=0; i<n; i++){
        w = values[i].first;
        v = values[i].second;

        for(int j=k; j >= w; j--){
            dp[j] = max(dp[j], dp[j-w] + v);
        }
    }

    cout << dp[k] << '\n';

    return 0;
}