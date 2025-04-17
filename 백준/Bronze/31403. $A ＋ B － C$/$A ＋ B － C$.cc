#include <iostream>
#include <cmath>
using namespace std;

int GetDigitCount(int num){
    if(num >=1 && num <=9) return 1;
    else if(num >=10 && num <= 99) return 2;
    else if(num >=100 && num <= 999) return 3;
    else return 4;
}

int main(){
    int a, b, c;
    int res1, res2;

    cin >> a >> b >> c;

    // used to shift a by the amount of digits in b
    int multiplier = 1;
    int loops = GetDigitCount(b);
    for(int i=0; i<loops; i++){
        multiplier *= 10;
    }

    res1 = (multiplier * a) + b - c;
    res2 = a + b - c;

    cout << res2 << "\n" << res1;
}
