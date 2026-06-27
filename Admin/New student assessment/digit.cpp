#include <bits/stdc++.h>
using namespace std;

int  ans;

int     main(){
    long long m, n;
    cin >> m >> n;

    for (long long i = m; i <= n; i ++){
        long long p = i;
        int d;
        while (p > 0){
            d = p % 10;
            if (d == 3 || d == 7){
                ans ++;
                break;
            }
            p /= 10;
        }
    }

    cout << ans << endl;

    return 0;
}
