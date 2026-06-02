#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, p=1, num=0;
    cin >> n;
    // convert n to binary, number of lights lighted euqals number of digits of the binary
    // find the smallest power of 2 great than n
    while(p <= n){
        p *= 2;
        ++ num;
    }
    cout << num;
    
    return 0;
}
