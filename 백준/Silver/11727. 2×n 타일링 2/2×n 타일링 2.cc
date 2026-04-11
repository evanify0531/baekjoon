#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int sum[1004];
int MOD = 10007;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    memset(sum, 0, sizeof(sum));

    sum[1] = 1;
    sum[2] = 3;

    for(int i=3; i<=n; i++){
        sum[i] = (sum[i-1] % MOD + ((sum[i-2] % MOD * 2) % MOD)) % MOD;
    }

    cout << sum[n];

    return 0;
}