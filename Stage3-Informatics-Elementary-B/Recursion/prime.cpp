#include <bits/stdc++.h>
using namespace std;

void    pf(int n, int p){
    if (n > 1){
        if (n%p == 0){
            cout << p << " ";
            pf(n/p, p);
        }else {
            pf(n, p+1);
        }
    }
}
int     main(){
    int n;
    cin >> n;

    pf(n, 2);

    return 0;
}
