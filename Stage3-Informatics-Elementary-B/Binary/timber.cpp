#include <bits/stdc++.h>
using namespace std;

int n, m, a[1000010];
int l, r;

bool check(int x){
    long long sum = 0;
    for (int i = 1; i <= n; i ++){
        if (a[i] > x)
            sum += a[i] - x;
    }
    return sum >= m;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        if (a[i] > r)
            r = a[i];
    }

    while (l <= r){
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << r << endl;
    
    return 0;
}