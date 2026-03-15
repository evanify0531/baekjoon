#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int sum=0, n, maxDay=-1;
    cin >> n;
    vector<pair<int, int>> p(n);
    for(int i=0; i<n; i++)
    {
        cin >> p[i].second >> p[i].first;
        maxDay = max(maxDay, p[i].second);
    }

    sort(p.begin(), p.end());

    //make it so top will produce the min value (minheap)
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++)
    {
        pq.push(p[i].second);
        //the size of the pq represents how many days we've spent
        //if the size of the pq is bigger than the current day, we have to choose the smallest
        //pay out of all the choices we've taken (greedy)
        // so we pop
        if(pq.size() > p[i].first)
        {
            pq.pop();
        }
    }
    while(pq.size())
    {
        sum += pq.top();
        pq.pop();
    }
    
    cout << sum << '\n';
    return 0;
}