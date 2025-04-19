#include <iostream>
using namespace std;

/// @brief Calculates how many bundles you need to buy at minimum to cover total. bundleSize not 0
/// @param total 
/// @param bundleSize 
/// @return 
int GetTShirtBundleCount(int total, int bundleSize){
    if (total % bundleSize == 0){
        return total / bundleSize;
    } else {
        // 나머지 값을 한 묶음으로 산다
        return total / bundleSize + 1;
    }
}

int main(){
    int tShirtCountBySize[6]; // 사이즈별 인원 수. 합은 n
    int t, p; // t: 한 묶음 티셔츠 수, p: 한 묶음 펜 수
    int n; // 전체 참가자 수

    int loopCount = sizeof(tShirtCountBySize) / sizeof(tShirtCountBySize[0]);

    // 구매할 묶음과 개별 펜의 수
    int tBundle = 0, pBundle = 0, pSingle = 0; 

    // 입력
    cin >> n;
    for(int i=0; i<loopCount; i++){
        cin >> tShirtCountBySize[i];
    }
    
    cin >> t >> p;

    for(int i=0; i<loopCount; i++){
        tBundle += GetTShirtBundleCount(tShirtCountBySize[i], t);
    }

    pBundle = n / p;
    pSingle = n % p;

    cout << tBundle << endl;
    cout << pBundle << ' ' << pSingle;

    return 0;
}