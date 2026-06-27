#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, num = 0;
    cin >> n;
    // 将n转为二进制数，该数有几位数字，就有几盏灯被点亮过
    // 将二进制数不断向右位移，直到变为0为止，位移了几次就有几位
    while(n){
        num ++;
        n >>= 1;
    }
    cout << num << endl;

    return 0;
}
