#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    int minimumJumps[50001] = {0};
    cin >> num;

    // 정리에 의해 불가능한 수로 초기화
    for(int i=1; i<=num; i++)
    {
        minimumJumps[i] = 5;
    }

    // 5만 이하 가장 큰 제곱수의 제곱근까지
    for(int i=1; i<=223; i++)
    {
        minimumJumps[i * i] = 1;
    }

    // 제곱수이면 1을 출력하고 바로 리턴한다.
    if(minimumJumps[num] == 1){
        cout << minimumJumps[num];
        return 0;
    }

    for(int i=2; i<=num; i++)
    {
        for(int j=1; j*j<i; j++)
        {
            int jSquared = j*j;
            int minJ = minimumJumps[jSquared];
            if(minJ > minimumJumps[i]) continue;
            int otherMin = minimumJumps[i - jSquared];
            minimumJumps[i] = min(minimumJumps[i], minJ + otherMin);
        }

    }

    cout << minimumJumps[num];
    return 0;
}