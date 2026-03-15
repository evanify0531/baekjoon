#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

int main() {
    int n;

    cin >> n;
    priority_queue<float, vector<float>, greater<float>> pq;

    float score;

    for(int i=0; i<n; i++){
        cin >> score;
        pq.push(score);
    }

    // for formatting to 3 decimal places
    cout << fixed << setprecision(3);

    for(int i=0; i<7; i++){
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}