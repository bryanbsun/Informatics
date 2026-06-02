#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, r, den, num;
    cin >> n;
    r = 1;

    while(n-r > 0){
        n -= r++;
    }

    den = r - n + 1;
    num = n;

    cout << num << "/" << den << endl;
    return 0;
}
