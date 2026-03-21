#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, total, num, lhs, rhs;
    priority_queue<int, vector<int>, greater<int>> minPq;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> num;
        minPq.push(num);
    }

    total = 0;

    while(minPq.size() > 1){
        lhs = minPq.top();
        minPq.pop();
        rhs = minPq.top();
        minPq.pop();
        total += (lhs + rhs);
        minPq.push(lhs + rhs);
    }

    cout << total << '\n';

    return 0;
}