#include <bits/stdc++.h>
using namespace std;

struct node{
    int v;
    int lc;
    int rs;
}a[110];

int n, r, k;

int     main(){
    cin >> n >> r;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].v >> a[i].lc >> a[i].rs;

    cin >> k;
    for (int i = 0; i < k; i ++){
        int x, ans = 0;
        cin >> x;
        for (int c = a[x].lc; c; c = a[c].rs)
            ans ++;
        cout << ans << endl;
    }

    return 0;
}
