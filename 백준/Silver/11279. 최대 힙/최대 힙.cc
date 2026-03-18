#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);


    int n;
    int x;
    int val;
    priority_queue<int, vector<int>, less<int>> pq; // max heap

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x;

        if(x == 0){
            if(pq.empty()) val = 0;
            else {
                val = pq.top();
                pq.pop();
            }

            cout << val <<'\n';
        } else {
            pq.push(x);
        }
    }

    return 0;
}