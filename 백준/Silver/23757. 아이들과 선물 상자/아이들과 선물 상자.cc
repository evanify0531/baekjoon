#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    int presentNumber, wish, maxPresents;
    priority_queue<int, vector<int>, less<int>> presentBoxes;

    cin >> n >> m;

    queue<int> wishes;

    for(int i=0; i<n; i++){
        cin >> presentNumber;
        presentBoxes.push(presentNumber);
    }

    for(int i=0; i<m; i++){
        cin >> wish;
        wishes.push(wish);
    }

    bool isSuccess = true;
    for(int i=0; i<m; i++){
        if(presentBoxes.size() == 0){
            isSuccess = false;
            break;
        }

        wish = wishes.front();
        maxPresents = presentBoxes.top();
        if(wish > maxPresents){
            isSuccess = false;
            break;
        }
        wishes.pop();
        presentBoxes.pop();
        if(wish < maxPresents) presentBoxes.push(maxPresents - wish);
    }

    cout << isSuccess ? 1 : 0 << '\n';
    
    return 0;
}