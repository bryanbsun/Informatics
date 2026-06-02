#include <bits/stdc++.h>
using namespace std;

int     n, a[100010];
long long m;

int     main(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    cin >> m;

    sort(a+1, a+n+1);

    int x, l, r, mid;
    for (int i = 1; i < n; i ++){
        x = a[i];
        l = i + 1;
        r = n;
        while (l <= r){
            mid = (l + r) / 2;
            if (a[mid] == m - x){
                cout << x << " " << a[mid] << endl;
                return 0;
            }else if (a[mid] < m - x)
                l = mid + 1;
            else if (a[mid] > m - x)
                r = mid - 1;
        }
    }
    cout << "No" << endl;
    return 0;
}
