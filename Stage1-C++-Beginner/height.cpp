#include <bits/stdc++.h>
using namespace std;
int     main(){
    int n, a, maxn = -1;
    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> a;
        if (a > maxn)
            maxn = a;
    }
    cout << maxn << endl;
    return 0; 
}