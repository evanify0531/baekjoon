#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>

using namespace std;

int n, m, cycles;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};

int graph[1004][1004];
int visited[1004][1004];

void dfs(int y, int x){
    visited[y][x] = 1;
    //cout << y << ' ' << x << endl;

    int nextNodeIdx = graph[y][x];
    int ny = y + dy[nextNodeIdx];
    int nx = x + dx[nextNodeIdx];

    if(ny < 0 || ny >= n || nx < 0 || nx >= m) return;
    if(visited[ny][nx] == 0) dfs(ny, nx);
    else if(visited[ny][nx] == 1) cycles++; 

    visited[y][x] = 2;
}

int GetSubCommand(char c){
    if(c == 'D') return 0;
    else if(c == 'L') return 1;
    else if(c == 'U') return 2;
    else return 3;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string cmd;
    char subCmd;

    cin >> n >> m;

    memset(graph, 0 , sizeof(graph));
    memset(visited, 0, sizeof(visited));

    for(int i=0; i<n; i++){
        cin >> cmd;
        for(int j=0; j<m; j++){
            subCmd = cmd[j];
            graph[i][j] = GetSubCommand(subCmd);
        }
    }

    cycles = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]) continue;
            dfs(i, j);
        }
    }

    cout << cycles << '\n';
    
    return 0;
}