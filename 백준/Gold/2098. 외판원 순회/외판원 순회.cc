// 16 bit number where 1 indicates visited city
// use dp 
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 16
const int INF = 987654321;

int n, dp[MAX_N][1 << MAX_N], dist[MAX_N][MAX_N];

void print()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<(1<<n); j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}

int tsp(int here, int visited)
{
    // if visited all cities, visited = 1111 ... 11.
    // this is equal to (1 << n) - 1
    // if there exists a path from here back to 0(our starting point)
    // we return the weight of the path, else we return INF
    if(visited == (1 << n) - 1)
    {
        return dist[here][0] ? dist[here][0] : INF;
    }

    int &ret = dp[here][visited];

    //this allows us to not consider solutions we already found an answer to
    if(ret != -1) return ret;
    // in order to find true minimum
    ret = INF;

    for(int i=0; i<n; i++)
    {
        if(visited & (1 << i)) continue;
        if(dist[here][i] == 0) continue;
        // min finds the smallest path
        // each dp equals the minimum weight sum that visits all cities
        // when given the current city and the state of all visited cities
        ret = min(ret, tsp(i, visited | (1 << i)) + dist[here][i]);
    }

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> dist[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << tsp(0, 1) << '\n';

    //print();
    return 0;
}