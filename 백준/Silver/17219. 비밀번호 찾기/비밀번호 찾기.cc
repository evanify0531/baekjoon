#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    string inputAddr, inputPw;
    unordered_map<string, string> map;
    cin >> n >> m;
    vector<string> searchAddrs;

    for(int i=0; i<n; i++){
        cin >> inputAddr >> inputPw;
        map[inputAddr] = inputPw;
    }

    for(int i=0; i<m; i++){
        cin >> inputAddr;
        searchAddrs.push_back(inputAddr);
    }

    for(int i=0; i<m; i++){
        cout << map[searchAddrs[i]] << '\n';
    }
    return 0;
}