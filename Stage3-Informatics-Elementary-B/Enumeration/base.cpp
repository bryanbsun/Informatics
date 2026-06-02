#include <bits/stdc++.h>
using namespace std;

long long   b2d(int n, int b){
    int bb = 1;
    long long nn = 0;
    while (n>0){
        if (n%10 >= b) return -1;
        nn += n%10 * bb;
        n /= 10;
        bb *= b;
    }

    return nn;
}

int     main(){
    int p, q, r;
    cin >> p >> q >> r;

    for (int b = 2; b <= 16; b ++){
        long long pp = b2d(p, b);
        long long qq = b2d(q, b);
        long long rr = b2d(r, b);

        if (pp >= 0 && qq >= 0 && rr >= 0 && pp * qq == rr){
            cout << b << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
