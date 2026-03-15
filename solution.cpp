#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> dayAndPayments(n);

    for(int i=0; i<n; i++){
        cin >> dayAndPayments[i].second >> dayAndPayments[i].first;
    }

    sort(dayAndPayments.begin(), dayAndPayments.end());

    priority_queue <int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; i++){
        pq.push(dayAndPayments[i].second);

        // 방금 푸시한 강연의 기한으로 인해 pq의 모든 강연을 참여할 수 없을 때 가장 가치(p)가 낮은 강의 제거
        if(pq.size() > dayAndPayments[i].first){
            pq.pop();
        }
    }

    int total = 0;
    while(pq.size()){
        total += pq.top();
        pq.pop();
    }

    cout << total << endl;
    return 0;
}