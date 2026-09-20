#include <bits/stdc++.h>
using namespace std;
int     n, r;
struct  node{
    int     v;
    int     lc, rc;
}bt[110];

void    pre(int n){
    if (!n)     return;
    cout << n << " ";
    pre(bt[n].lc);
    pre(bt[n].rc);
}

void    in(int n){
    if (!n)     return;
    in(bt[n].lc);
    cout << n << " ";
    in(bt[n].rc);
}

void    post(int n){
    if (!n)     return;
    post(bt[n].lc);
    post(bt[n].rc);
    cout << n << " ";
}

int     main(){
    cin >> n >> r;

    for(int i = 1; i <= n; i ++)
        cin >> bt[i].lc >> bt[i].rc;
    
    pre(r);
    cout << endl;
    in(r);
    cout << endl;
    post(r);
    cout << endl;

    return 0;
}