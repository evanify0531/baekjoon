#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void){
    string inputs[3];
    int firstNumber, firstNumberIndex, outputNumber;
    stringstream ss;

    cin >> inputs[0] >> inputs[1] >> inputs[2];

    for(int i=0; i<3; i++){
        if(inputs[i][0] == 'F') continue;
        if(inputs[i][0] == 'B') continue;

        // 여기까지 왔으면 Fizz, Buzz, FizzBuzz도 아니므로 숫자다.
        ss << inputs[i];
        ss >> firstNumber;
        firstNumberIndex = i;
        break;
    }

    outputNumber = firstNumber + (3 - firstNumberIndex);

    // 결과 출력
    if(outputNumber % 3 == 0 && outputNumber % 5 == 0){
        cout << "FizzBuzz";
    } else if(outputNumber % 3 == 0 && outputNumber % 5 != 0){
        cout << "Fizz";
    } else if(outputNumber % 3 != 0 && outputNumber % 5 == 0){
        cout << "Buzz";
    } else {
        cout << outputNumber;
    }

    return 0;
}