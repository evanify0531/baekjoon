#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int storage[21][21][21];
string delimiter = ", ";

int funcW(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20) return funcW(20, 20, 20);

    if(storage[a][b][c] != 0) return storage[a][b][c];

    if(a < b && b < c) {
        storage[a][b][c] = funcW(a, b, c-1) + funcW(a, b-1, c-1) - funcW(a, b-1, c);
        return storage[a][b][c];
    } else {
        storage[a][b][c] = funcW(a-1, b, c) + funcW(a-1, b-1, c) + funcW(a-1, b, c-1) - funcW(a-1, b-1, c-1);
        return storage[a][b][c]; 
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, c, ret;

    while(true){
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;

        ret = funcW(a, b, c);
        cout << "w(" << a << delimiter << b << delimiter << c << ") = " << ret << '\n';
    }

    return 0;
}