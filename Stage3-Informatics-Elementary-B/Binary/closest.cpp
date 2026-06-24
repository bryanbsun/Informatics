#include <bits/stdc++.h>
using namespace std;

int n, a[100010], m, x;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    cin >> m;

    int l, r, mid;
    int ans;
    for (int i = 0; i < m; i ++){
        cin >> x;
        l = 1;
        r = n; 
        while (l <= r){
            mid = (l + r) / 2;
            if (a[mid] <= x)
                l = mid + 1;
            else
                r = mid - 1;
        }

        if (r == 0)
            ans = a[1];
        else if (l > n)
            ans = a[n];
        else if (a[l] - x >= x - a[l-1])
            ans = a[l-1];
        else 
            ans = a[l];

        cout << ans << endl;
    }
    return 0;
}
