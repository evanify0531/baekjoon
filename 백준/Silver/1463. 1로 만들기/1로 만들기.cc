#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int minOps[1000004];

bool IsValid(int m){
    return m >= 0 && m <= 1000000;
}

void ConstructMinOps(int max){
    int val;
    minOps[1] = 0;

    for(int i=1; i<=max; i++){
        val = i + 1;
        if(IsValid(val)) minOps[val] = min(minOps[val], minOps[i] + 1);
        val = i * 2;
        if(IsValid(val)) minOps[val] = min(minOps[val], minOps[i] + 1);
        val = i * 3;
        if(IsValid(val)) minOps[val] = min(minOps[val], minOps[i] + 1);
    }

}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;

    cin >> n;

    fill(minOps, minOps + 1000004, 1000000000);

    ConstructMinOps(n);

    cout << minOps[n] << '\n';

    return 0;
}