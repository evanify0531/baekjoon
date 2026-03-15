#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

const int MAX = 7;

int main() {
    int n;

    cin >> n;
    priority_queue<float, vector<float>, less<float>> pq;

    float score;

    for(int i=0; i<n; i++){
        cin >> score;
        
        if(pq.size() < MAX){
            pq.push(score);
        } else {
            if(score < pq.top()){
                pq.pop();
                pq.push(score);
            }

        }
    }

    // for formatting to 3 decimal places
    cout << fixed << setprecision(3);

    float lowestScores[MAX]; 

    for(int i=0; i<MAX; i++){
        lowestScores[MAX - i - 1] = pq.top();
        pq.pop();
    }

    for (int i=0; i<MAX; i++) cout <<  lowestScores[i] << endl;

    return 0;
}