#include <bits/stdc++.h>
using namespace std;

int n, m, a[100010];

bool   check(int x){
    int total = 0, xm = 1;
    for (int i = 1; i <= n; i ++){
        total += a[i];
        if (total > x){
            xm ++;
            total = a[i];
        }
    }
//    cout << x << ", " << xm << endl;
    return (xm <= m);
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    int l = 1, r = 1000000001;
    while (l <= r){
        int mid = (l + r)/2;
//        cout << l << ", " << r << ", " << mid << endl;
        if (!check(mid))
            l = mid + 1;
        else 
            r = mid - 1;
    }

    cout << l << endl;
    
    return 0;
}
