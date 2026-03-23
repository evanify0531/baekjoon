#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int graph[1004];
bool visited[1004];

void dfs(int node){
    if(visited[node] == 1) return;

    visited[node] = 1;
    dfs(graph[node]);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t, n, num, cycles;

    cin >> t;

    while(t--){
        cycles = 0;
        cin >> n;

        memset(graph, 0 , sizeof(graph));
        memset(visited, 0, sizeof(visited));

        for(int i=1; i<=n; i++){
            cin >> num;
            graph[i] = num;
        }

        for(int i=1; i<=n; i++){
            if(visited[i] == 1) continue;
            cycles++;
            dfs(i);
        }

        cout << cycles << '\n';
    }

    return 0;
}