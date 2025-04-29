#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, t;
    long arr[101] = {0};

    cin >> n;

    arr[1] = 1; arr[2] = 1; arr[3] = 1; arr[4] = 2; arr[5] = 2;

    for(int i=6; i<=100; i++)
    {
        arr[i] = arr[i-1] + arr[i-5];
    }

    for(int i=0; i<n; i++)
    {
        cin >> t;
        cout << arr[t] << '\n';
    }

    return 0;
}