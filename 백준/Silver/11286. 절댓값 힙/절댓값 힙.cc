#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int n;
    int x;
    priority_queue<int, vector<int>, greater<int>> positivePq; // min heap
    priority_queue<int, vector<int>, less<int>> negativePq; // max heap

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x;

        if(x > 0) {
            positivePq.push(x);
        } else if(x < 0){
            negativePq.push(x);
        } else {
            if(positivePq.size() == 0 && negativePq.size() == 0){
                cout << 0 << '\n';
            } else if(positivePq.size() != 0 && negativePq.size() == 0) {
                cout << positivePq.top() << '\n';
                positivePq.pop();
            } else if(positivePq.size() == 0 && negativePq.size() != 0) {
                cout << negativePq.top() << '\n';
                negativePq.pop();
            } else if(positivePq.size() != 0 && negativePq.size() != 0) {
                int positiveVal = positivePq.top();
                int negativeVal = negativePq.top();
                int positiveAbs = abs(positiveVal);
                int negativeAbs = abs(negativeVal);

                if(positiveAbs < negativeAbs){
                    cout << positiveVal << '\n';
                    positivePq.pop();
                } else {
                    cout << negativeVal << '\n';
                    negativePq.pop();
                }
            }
        }
    }

    return 0;
}