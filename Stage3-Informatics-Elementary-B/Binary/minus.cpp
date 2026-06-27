#include <bits/stdc++.h>
using namespace std;

int     n, c;
int     a[1000010];
int     ans;

int     main(){
    cin >> n >> c;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    sort(a+1, a+n+1);

    for (int i = 1; i <= n; i ++){
        int x = a[i];
        int l = i + 1, r = n;
        int m;
        while (l <= r){
            m = (l + r)/2;
            if (a[m] <= c + x)
                l = m + 1;
            else
                r = m - 1;
        }
        int n1 = r;

        l = i + 1; r = n;
        while (l <= r){
            m = (l + r)/2;
            if (a[m] < c + x)
                l = m + 1;
            else
                r = m - 1;
        }
        int n2 = l;

        if (n1 <= n && n2 >= i + 1)
            ans += max(n1 - n2 + 1, 0);
    }

    cout << ans << endl;

    return 0;
}
