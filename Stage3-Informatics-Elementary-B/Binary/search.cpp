#include <bits/stdc++.h>
using namespace std;

int a[100010], n, m;

int a1(int x){
    int l = 1, r = n;
    while (l <= r){
        int m = (l + r) / 2;
        if (a[m] <= x)
            l = m + 1;
        else 
            r = m - 1;
    }

    if (l <= n)
        return l;
    else 
        return -1;
}

int a2(int x){
    int l = 1, r = n;
    while (l <= r){
        int m = (l + r) / 2;
        if (a[m] < x)
            l = m + 1;
        else 
            r = m - 1;
    }

    if (l <= n)
        return l;
    else 
        return -1;
}

int a3(int x){
    int l = 1, r = n;
    while (l <= r){
        int m = (l + r) / 2;
        if (a[m] < x)
            l = m + 1;
        else 
            r = m - 1;
    }

    if (r > 0)
        return r;
    else 
        return -1;
}

int a4(int x){
    int l = 1, r = n;
    while (l <= r){
        int m = (l + r) / 2;
        if (a[m] <= x)
            l = m + 1;
        else 
            r = m - 1;
    }

    if (r > 0)
        return r;
    else 
        return -1;
}

int a5(int x){
    if (a[1] < x)
        return 1;
    else 
        return -1;
}

int a6(int x){
    if (a[n] > x)
        return n;
    else 
        return -1;
}

int main(){
    int x;

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 0; i < m ; i ++){
        cin >> x;
        cout << a1(x) << " " << a2(x) << " " << a3(x) << " " << a4(x) << " " << a5(x) << " " << a6(x) << endl;
    }
    return 0;
}
