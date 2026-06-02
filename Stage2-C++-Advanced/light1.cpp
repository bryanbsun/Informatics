#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, num=0;
    cin >> n;
    // convert n to binary, number of lights lighted equals the number digits of the binary
    // repeatedly divid n by 2, until gets 0. answer is number of divisions
    while(n){
        num ++;
        n /= 2;
    }
    cout << num << endl;
    
    return 0;
}
