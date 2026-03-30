#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <set>

using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};

set<string> visited;
int ret = -1;
string start;
string Answer = "123456780";

bool IsValid(int y, int x){
    if(y < 0 || y >= 3 || x < 0 || x >= 3) return false;
    return true;
}


void BFS(){
    // string은 상태, int는 이 상태를 도달하기 위한 작업의 횟수
    queue<pair<string, int>> bfsQ;
    string currentStr;
    int cnt;
    bfsQ.push(make_pair(start, 0));
    visited.insert(start);

    while(!bfsQ.empty()){
        pair<string, int> currentPair = bfsQ.front();
        bfsQ.pop();

        currentStr = currentPair.first;
        cnt = currentPair.second;

        if(currentStr.compare(Answer) == 0){
            ret = cnt;
            return;
        }

        int zeroIdx = currentStr.find('0');
        int y = zeroIdx / 3;
        int x = zeroIdx % 3;

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(!IsValid(ny, nx)) continue;

            auto tmp = currentStr;
            swap(tmp[y * 3 + x], tmp[ny * 3 + nx]);
            // if not in visited
            if(visited.find(tmp) == visited.end()){
                visited.insert(tmp);
                bfsQ.push(make_pair(tmp, cnt + 1));
            }
        }


    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    char c;

    for(int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cin >> c;
            start += c;
        }
    }

    BFS();

    cout << ret << '\n';

    return 0;
}