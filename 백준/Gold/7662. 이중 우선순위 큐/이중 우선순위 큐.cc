#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t, k, n, subCommand, deleteMark;
    char command;
    map<int, int> cnt;

    cin >> t;

    for(int i=0; i<t; i++){
        cin >> k;

        priority_queue<int, vector<int>, less<int>> maxPq;
        priority_queue<int, vector<int>, greater<int>> minPq;
        cnt.clear();

        for(int j=0; j<k; j++){
            cin >> command;
            if(command == 'I'){
                cin >> subCommand;
                maxPq.push(subCommand);
                minPq.push(subCommand);
                cnt[subCommand]++;
            }
            else if(command == 'D'){
                cin >> subCommand;
                if(subCommand == 1){
                    if(maxPq.size() == 0) continue;
                    deleteMark = maxPq.top();
                    maxPq.pop();
                    cnt[deleteMark]--;
                } else {
                    if(minPq.size() == 0) continue;
                    deleteMark = minPq.top();
                    minPq.pop();
                    cnt[deleteMark]--;
                }

                // 다음 D를 하기 전에 반대편 pq에 남아 있을 때를 대비하여 정리해준다.
                while(!minPq.empty() && cnt[minPq.top()] == 0){
                    minPq.pop();
                }

                while(!maxPq.empty() && cnt[maxPq.top()] == 0){
                    maxPq.pop();
                }
            }
        }

        if(minPq.empty() || maxPq.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << maxPq.top() << ' ' << minPq.top() << '\n';
        }
    }

    
    return 0;
}