#include <bits/stdc++.h>
using namespace std;
int n, r, k;
struct node{
    int v;
    int lc, rs;
}t[110];

int     find(int x, int y){
    if (!x) return 0;
    for (int p = t[x].lc; p; p = t[p].rs)
        if find(p, y) return true;
    return false;
}

int     main(){
    cin >> n >> r;
    for (int i = 1; i <= n; i ++)
        cin >> t[i].v >> t[i].lc >> t[i].rs;

    cin >> k;
    int x, y;
    for (int i = 0; i < k; i ++){
        cin >> x >> y;
        for (int p = t[x].lc; p; p = t[p].rs)
            if (find(p, y)){
                cout << x << endl;
                break;
            }
        
        for (int p = t[y].lc; p; p = t[p].rs)
            if (find(p, x)){
                cout << y << endl;
                break;
            }
        
    }
    return 0;
}