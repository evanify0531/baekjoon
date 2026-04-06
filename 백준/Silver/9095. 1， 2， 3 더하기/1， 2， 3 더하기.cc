#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int sum[12];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t, n;
    memset(sum, 0, sizeof(sum));

    sum[1] = 1;
    sum[2] = 2;
    sum[3] = 4;

    for(int i=4; i<12; i++){
        sum[i] = sum[i-1] + sum[i-2] + sum[i-3];
    }


    cin >> t;

    while(t--){
        cin >> n;
        cout << sum[n] << '\n';
    }

    return 0;
}