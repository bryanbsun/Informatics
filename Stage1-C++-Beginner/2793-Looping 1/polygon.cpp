#include <bits/stdc++.h>
using namespace std;
int  n, a, sum = 0;

int     main(){
    cin >> n;
    for (int i = 0; i < n-1; i ++){
        cin >> a;
        sum += a;
    }

    cout << (n-2)*180 - sum << endl;
    return 0;
}