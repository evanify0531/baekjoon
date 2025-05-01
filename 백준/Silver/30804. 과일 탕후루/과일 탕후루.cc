#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, types=0;
    int totalMax = -1;
    int cnt[10] = {0};
    queue<int> curQ;

    cin >> n;

    for(int i=0; i<n; i++)
    {
        int fruit;
        cin >> fruit;

        curQ.push(fruit);
        cnt[fruit]++;

        if(cnt[fruit] == 1)
        {
            types++;
        }

        while(types > 2)
        {
            fruit = curQ.front();
            curQ.pop();
            cnt[fruit]--;

            if(cnt[fruit] == 0)
            {
                types--;
            }
        }

        totalMax = max(totalMax, static_cast<int>(curQ.size()));
    }

    cout << totalMax;
    return 0;
}